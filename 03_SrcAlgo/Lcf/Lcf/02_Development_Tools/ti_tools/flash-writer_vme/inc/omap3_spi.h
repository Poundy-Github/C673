/*
 * Register definitions for the OMAP3 McSPI Controller
 *
 * Copyright (C) 2010 Dirk Behme <dirk.behme@googlemail.com>
 *
 * Parts taken from linux/drivers/spi/omap2_mcspi.c
 * Copyright (C) 2005, 2006 Nokia Corporation
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */
#include "spi_flash_internal.h"

#ifdef CONFIG_TI816X_EVM
	/* TODO should we add 0x100 to base ? see McSPI spec register map */
	#define OMAP3_MCSPI1_BASE		0x48030100
#else
	#ifdef CONFIG_TI814X_EVM
		#define OMAP3_MCSPI1_BASE		0x48030100 /* only mcspi-1 is used */
		#define OMAP3_MCSPI2_BASE		0x481A0000
		#define OMAP3_MCSPI3_BASE		0x481A2000
		#define OMAP3_MCSPI4_BASE		0x481A4000
		#define CFG_MOD_BASE			0x48140000
	#else
		#define OMAP3_MCSPI1_BASE		0x48098000
		#define OMAP3_MCSPI2_BASE		0x4809A000
		#define OMAP3_MCSPI3_BASE		0x480B8000
		#define OMAP3_MCSPI4_BASE		0x480BA000
	#endif
#endif

#define OMAP3_MCSPI_MAX_FREQ		48000000

/* OMAP3 McSPI registers */
struct mcspi_channel {
	unsigned int chconf;		/* 0x2C, 0x40, 0x54, 0x68 */
	unsigned int chstat;		/* 0x30, 0x44, 0x58, 0x6C */
	unsigned int chctrl;		/* 0x34, 0x48, 0x5C, 0x70 */
	unsigned int tx;		/* 0x38, 0x4C, 0x60, 0x74 */
	unsigned int rx;		/* 0x3C, 0x50, 0x64, 0x78 */
};

struct mcspi {
	unsigned char res1[0x10];
	unsigned int sysconfig;		/* 0x10 */
	unsigned int sysstatus;		/* 0x14 */
	unsigned int irqstatus;		/* 0x18 */
	unsigned int irqenable;		/* 0x1C */
	unsigned int wakeupenable;	/* 0x20 */
	unsigned int syst;		/* 0x24 */
	unsigned int modulctrl;		/* 0x28 */
	struct mcspi_channel channel[4]; /* channel0: 0x2C - 0x3C, bus 0 & 1 & 2 & 3 */
					/* channel1: 0x40 - 0x50, bus 0 & 1 */
					/* channel2: 0x54 - 0x64, bus 0 & 1 */
					/* channel3: 0x68 - 0x78, bus 0 */
};

/* per-register bitmasks */
#define OMAP3_MCSPI_SYSCONFIG_SMARTIDLE	(2 << 3)
#define OMAP3_MCSPI_SYSCONFIG_ENAWAKEUP	(1 << 2)
#define OMAP3_MCSPI_SYSCONFIG_AUTOIDLE	(1 << 0)
#define OMAP3_MCSPI_SYSCONFIG_SOFTRESET	(1 << 1)

#define OMAP3_MCSPI_SYSSTATUS_RESETDONE	(1 << 0)

#define OMAP3_MCSPI_MODULCTRL_SINGLE	(1 << 0)
#define OMAP3_MCSPI_MODULCTRL_MS	(1 << 2)
#define OMAP3_MCSPI_MODULCTRL_STEST	(1 << 3)

#define OMAP3_MCSPI_CHCONF_PHA		(1 << 0)
#define OMAP3_MCSPI_CHCONF_POL		(1 << 1)
#define OMAP3_MCSPI_CHCONF_CLKD_MASK	(0x0f << 2)
#define OMAP3_MCSPI_CHCONF_EPOL		(1 << 6)
#define OMAP3_MCSPI_CHCONF_WL_MASK	(0x1f << 7)
#define OMAP3_MCSPI_CHCONF_TRM_RX_ONLY	(0x01 << 12)
#define OMAP3_MCSPI_CHCONF_TRM_TX_ONLY	(0x02 << 12)
#define OMAP3_MCSPI_CHCONF_TRM_MASK	(0x03 << 12)
#define OMAP3_MCSPI_CHCONF_DMAW		(1 << 14)
#define OMAP3_MCSPI_CHCONF_DMAR		(1 << 15)
#define OMAP3_MCSPI_CHCONF_DPE0		(1 << 16)
#define OMAP3_MCSPI_CHCONF_DPE1		(1 << 17)
#define OMAP3_MCSPI_CHCONF_IS		(1 << 18)
#define OMAP3_MCSPI_CHCONF_TURBO	(1 << 19)
#define OMAP3_MCSPI_CHCONF_FORCE	(1 << 20)
#define OMAP3_MCSPI_CHCONF_TCS		(1 << 25)
#define OMAP3_MCSPI_CHCONF_FFEW		(1 << 27)
#define OMAP3_MCSPI_CHCONF_FFER		(1 << 28)


#define OMAP3_MCSPI_CHSTAT_RXS		(1 << 0)
#define OMAP3_MCSPI_CHSTAT_TXS		(1 << 1)
#define OMAP3_MCSPI_CHSTAT_EOT		(1 << 2)

#define OMAP3_MCSPI_CHCTRL_EN		(1 << 0)

#define OMAP3_MCSPI_WAKEUPENABLE_WKEN	(1 << 0)

/*-----------------------------------------------------------------------
 * Representation of a SPI slave, i.e. what we're communicating with.
 *
 * Drivers are expected to extend this with controller-specific data.
 *
 *   bus:       ID of the bus that the slave is attached to.
 *   cs:        ID of the chip select connected to the slave.
 */
struct spi_slave {
        unsigned int    bus;
        unsigned int    cs;
};

struct spi_flash {
	struct spi_slave *spi;
	const char      *name;
	Uint32			size;
	int             (*read)(struct spi_flash *flash, Uint32 offset, Uint32 len, void *buf);
	int             (*write)(struct spi_flash *flash, Uint32 offset, Uint32 len, Uint8 *buf);
	int             (*erase)(struct spi_flash *flash, Uint32 offset, Uint32 len);
};


struct omap3_spi_slave {
	struct spi_slave	slave;
	struct mcspi volatile *regs;
	unsigned int		freq;
	unsigned int		mode;
};

/* SPI transfer flags */
#define SPI_XFER_BEGIN  0x01		/* Assert CS before transfer */
#define SPI_XFER_END    0x02        /* Deassert CS after transfer */

struct winbond_spi_flash_params {
	unsigned short idcode;
	unsigned short page_size;
	unsigned short pages_per_sector;
	unsigned short nr_sectors;
	const char *name;
};
struct winbond_spi_flash {
	const struct winbond_spi_flash_params *params;
	struct spi_flash flash;
};

struct stmicro_spi_flash_params {
	unsigned short idcode1;
	unsigned short page_size;
	unsigned short pages_per_sector;
	unsigned short nr_sectors;
	const char *name;
};
struct stmicro_spi_flash {
	const struct stmicro_spi_flash_params *params;
	struct spi_flash flash;
};


#define offsetof(TYPE, MEMBER) ((Uint32) &((TYPE *)0)->MEMBER)

/**
 * container_of - cast a member of a structure out to the containing structure
 * @ptr:        the pointer to the member.
 * @type:       the type of the container struct this is embedded in.
 * @member:     the name of the member within the struct.
 *
 */
#define container_of(ptr, type, member) \
		( (type *)( (char *)ptr - offsetof(type,member) ) )

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

static inline struct omap3_spi_slave *to_omap3_spi(struct spi_slave *slave)
{
	return container_of(slave, struct omap3_spi_slave, slave);
}


static inline struct winbond_spi_flash *to_winbond_spi_flash(struct spi_flash
							     *flash)
{
	return container_of(flash, struct winbond_spi_flash, flash);
}

static inline struct stmicro_spi_flash *to_stmicro_spi_flash(struct spi_flash
							     *flash)
{
	return container_of(flash, struct stmicro_spi_flash, flash);
}

/* Send a single-byte command to the device and read the response */
int spi_flash_cmd(struct spi_slave *spi, Uint8 cmd, void *response, Uint32 len);

/*
 * Send a multi-byte command to the device and read the response. Used
 * for flash array reads, etc.
 */
int spi_flash_cmd_read(struct spi_slave *spi, const Uint8 *cmd,
		Uint32 cmd_len, void *data, Uint32 data_len);

/*
 * Send a multi-byte command to the device followed by (optional)
 * data. Used for programming the flash array, etc.
 */
int spi_flash_cmd_write(struct spi_slave *spi, const Uint8 *cmd, Uint32 cmd_len,
		const void *data, Uint32 data_len);

/*
 * Same as spi_flash_cmd_read() except it also claims/releases the SPI
 * bus. Used as common part of the ->read() operation.
 */
int spi_flash_read_common(struct spi_flash *flash, const Uint8 *cmd,
		Uint32 cmd_len, void *data, Uint32 data_len);

/* Manufacturer-specific probe functions */
struct spi_flash *spi_flash_probe_spansion(struct spi_slave *spi, Uint8 *idcode);
struct spi_flash *spi_flash_probe_atmel(struct spi_slave *spi, Uint8 *idcode);
struct spi_flash *spi_flash_probe_stmicro(struct spi_slave *spi, Uint8 *idcode);
struct spi_flash *spi_flash_probe_winbond(struct spi_slave *spi, Uint8 *idcode);

int spi_claim_bus(struct spi_slave *slave);
struct spi_slave *spi_setup_slave(unsigned int bus, unsigned int cs, unsigned int max_hz, unsigned int mode);
int spi_xfer(struct spi_slave *slave, unsigned int bitlen, const void *dout, void *din, unsigned long flags);
void spi_release_bus(struct spi_slave *slave);
void spi_free_slave(struct spi_slave *slave);
