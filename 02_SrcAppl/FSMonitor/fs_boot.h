#ifndef FS_BOOT_H
#define FS_BOOT_H

/**
 * @brief Read out cat storage section.
 * It is supposed call before OS starts
*/
void FS_Boot(void);

/**
 * @brief Check Cat2 number and Enter Endless 
 * mode according to Cat2 number
 * 
 * When CAT2=3 Endless mode will entered.
 * 
 * during endless mode.It check KL15 level constantly
 * 
 * If KL15 drop below 6 (with a debounce filter ).
 * CAT2 count will be reset and a reset is performed.
*/
void FS_BootEndlessModeCheck(void);

#endif /* FS_BOOT_H */
