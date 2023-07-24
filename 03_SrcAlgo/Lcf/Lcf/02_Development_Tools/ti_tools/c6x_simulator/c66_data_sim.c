/****************************************************************************/
/*  c66_data_sim.c                                                          */
/*  Copyright (c) 1997-2010  Texas Instruments Incorporated                 */
/****************************************************************************/

/****************************************************************************/
/* the includes                                                             */
#include <math.h>
#include <float.h>
#include <assert.h>
#include "C6xSimulator.h"

#define TYPE_PUN(type, var) (*((type *) &var))
#define LL_TO_LO32(type, ll) ((type) ((ll) & 0xffffffff))
#define LL_TO_HI32(type, ll) ((type) (((ll) >> 32) & 0xffffffff))
#define DBL_TO_LO32(type, d) (LL_TO_LO32(type, TYPE_PUN(uint64_ll, d)))
#define DBL_TO_HI32(type, d) (LL_TO_HI32(type, TYPE_PUN(uint64_ll, d)))

#ifdef TMS320C66X
__x128_t _ito128(uint32 arg3, uint32 arg2, uint32 arg1, uint32 arg0)
{
   __x128_t temp;
   temp.word0 = arg0;
   temp.word1 = arg1;
   temp.word2 = arg2;
   temp.word3 = arg3;
   return temp;
}

__x128_t _fto128(float32 arg3, float32 arg2, float32 arg1, float32 arg0)
{
   __x128_t temp;
   temp.word0 = TYPE_PUN(uint32, arg0);
   temp.word1 = TYPE_PUN(uint32, arg1);
   temp.word2 = TYPE_PUN(uint32, arg2);
   temp.word3 = TYPE_PUN(uint32, arg3);
   return temp;
}
                                  
__x128_t _llto128(int64_ll arg1, int64_ll arg0)
{
   __x128_t temp;
   temp.word0 = LL_TO_LO32(uint32, arg0);
   temp.word1 = LL_TO_HI32(uint32, arg0);
   temp.word2 = LL_TO_LO32(uint32, arg1);
   temp.word3 = LL_TO_HI32(uint32, arg1);
   return temp;
}

__x128_t _dto128(double64 arg1, double64 arg0)
{
   __x128_t temp;
   temp.word0 = DBL_TO_LO32(uint32, arg0);
   temp.word1 = DBL_TO_HI32(uint32, arg0);
   temp.word2 = DBL_TO_LO32(uint32, arg1);
   temp.word3 = DBL_TO_HI32(uint32, arg1);
   return temp;
}

__x128_t _f2to128(__float2_t arg1, __float2_t arg0)
{
   __x128_t temp;
   temp.word0 = arg0.word0;
   temp.word1 = arg0.word1;
   temp.word2 = arg1.word0;
   temp.word3 = arg1.word1;
   return temp;
}

__x128_t _dup32_128(uint32 arg)
{
   __x128_t temp;
   temp.word0 = arg;
   temp.word1 = arg;
   temp.word2 = arg;
   temp.word3 = arg;
   return temp;
}

double64 _lltod(int64_ll arg)
{
   return TYPE_PUN(double64, arg);
}

__float2_t _lltof2(int64_ll arg)
{
   __float2_t temp;
   temp.word0 = (uint32) (arg & 0xffffffff);
   temp.word1 = (uint32) ((arg >> 32) & 0xffffffff);
   return temp;
}

int64_ll _dtoll(double64 arg)
{
   return TYPE_PUN(int64_ll, arg);
}

int64_ll _f2toll(__float2_t arg)
{
   return (int64_ll) arg.word1 << 32 | arg.word0;
}

float32 _hif(double64 arg)
{
   uint32 temp = DBL_TO_HI32(uint32, arg);
   return TYPE_PUN(float32, temp);
}

float32 _lof(double64 arg)
{
   uint32 temp = DBL_TO_LO32(uint32, arg);
   return TYPE_PUN(float32, temp);
}

float32 _hif2(__float2_t arg)
{
   uint32 temp = arg.word1;
   return TYPE_PUN(float32, temp);
}

float32 _lof2(__float2_t arg)
{
   uint32 temp = arg.word0;
   return TYPE_PUN(float32, temp);
}

int64_ll _hi128(__x128_t arg)
{
   return (int64_ll) arg.word3 << 32 | arg.word2;
}

double64 _hid128(__x128_t arg)
{
   int64_ll temp = (int64_ll) arg.word3 << 32 | arg.word2;
   return TYPE_PUN(double64, temp);
}

__float2_t _hif2_128(__x128_t arg)
{
   __float2_t temp;
   temp.word1 = arg.word3;
   temp.word0 = arg.word2;
   return temp;
}

int64_ll _lo128(__x128_t arg)
{
   return (int64_ll) arg.word1 << 32 | arg.word0;
}

double64 _lod128(__x128_t arg)
{
   int64_ll temp = (int64_ll) arg.word1 << 32 | arg.word0;
   return TYPE_PUN(double64, temp);
}

__float2_t _lof2_128(__x128_t arg)
{
   __float2_t temp;
   temp.word1 = arg.word1;
   temp.word0 = arg.word0;
   return temp;
}

//----------------------------------------------------------------------------
// For the get32 functions, the second argument is limited by the TI   
// compiler to a constant literal (i.e. variables and expressions not 
// accepted) in the range 0-3.  Those limitations cannot be modeled
// here.  The assert check helps a bit.
//----------------------------------------------------------------------------
uint32 _get32_128(__x128_t arg, unsigned index)
{
   assert(0 <= index && index <= 3);
   
   switch (index)
   {
      case 0 : return arg.word0;
      case 1 : return arg.word1;
      case 2 : return arg.word2;
      case 3 : return arg.word3;
   }

   return 0;      // Not reached.  But silences compiler warnings.
}

float32 _get32f_128(__x128_t arg, unsigned index)
{
   assert(0 <= index && index <= 3);
   
   switch (index)
   {
      case 0 : return TYPE_PUN(float32, arg.word0);
      case 1 : return TYPE_PUN(float32, arg.word1);
      case 2 : return TYPE_PUN(float32, arg.word2);
      case 3 : return TYPE_PUN(float32, arg.word3);
   }

   return 0.0;    // Not reached.  But silences compiler warnings.
}

#endif // #ifdef TMS320C66X


/*
 *  Automated Revision Information
 *  Changed: $Date: 2021/12/13 19:18:06CET $
 *  Revision: $Revision: 1.1 $
 */
/* 

C6000 Host Intrinsics Software License Agreement


IMPORTANT - PLEASE READ THE FOLLOWING LICENSE AGREEMENT CAREFULLY.  
THIS IS A LEGALLY BINDING AGREEMENT.  AFTER YOU READ THIS LICENSE 
AGREEMENT, YOU WILL BE ASKED WHETHER YOU ACCEPT AND AGREE TO THE 
TERMS OF THIS LICENSE AGREEMENT.  DO NOT CLICK  "I HAVE READ AND AGREE" 
UNLESS: (1) YOU ARE AUTHORIZED TO ACCEPT AND AGREE TO THE TERMS OF THIS 
LICENSE AGREEMENT ON BEHALF OF YOURSELF AND YOUR COMPANY; AND (2) YOU 
INTEND TO ENTER INTO AND TO BE BOUND BY THE TERMS OF THIS LEGALLY 
BINDING AGREEMENT ON BEHALF OF YOURSELF AND YOUR COMPANY.


Important - Read carefully: This C6000 Host Intrinsics Software License 
Agreement ("Agreement") is a legal agreement between you (either an 
individual or entity) and Texas Instruments Incorporated ("TI").  The 
"Licensed Materials" subject to this Agreement include the software 
programs that TI has granted you access to download with this Agreement 
and any "on-line" or electronic documentation associated with these 
programs, or any portion thereof, as well as any updates or upgrades to such 
software programs and documentation, if any, or any portion thereof, 
provided to you in TI's sole discretion.  By installing, copying or otherwise 
using the Licensed Materials you agree to abide by the following provisions.  
This Agreement is displayed for you to read prior to using the Licensed 
Materials.  If you choose not to accept or agree with these provisions, do not 
download or install the Licensed Materials. 

1.	License Grant and Use Restrictions.

a.	License Grant.  Subject to the terms of this Agreement, TI hereby 
grants to you under all TI intellectual property rights embodied in the 
Licensed Materials a limited, non-exclusive, non-transferable, non-
assignable, fully paid-up, royalty-free, non-sublicensable license only to 
(i) use the Licensed Materials solely for the purposes of evaluating, 
testing, debugging and optimizing applications ("Target Applications") 
that execute solely and exclusively on processing devices manufactured 
by or for TI ("TI Devices"), and (ii) make a reasonable number of copies 
necessary to exercise the right granted to you in Section 1(a)(i) above.  
Use of any software applications optimized or developed using the 
Licensed Materials on processing devices manufactured by or for an 
entity other than TI is a material breach of this Agreement.  It is also a 
material breach of this license to use the Licensed Materials to assist in 
the design, development or verification of a device that is instruction set 
compatible with, or functionally equivalent to, a TI processing device.

b.	Contractors and Suppliers.  The licenses granted to you hereunder 
shall include your on-site and off-site suppliers and independent 
contractors, while such suppliers and independent contractors are 
performing work for or providing services to you, provided that such 
suppliers and independent contractors have executed work-for-hire 
agreements with you containing terms and conditions not inconsistent 
with the terms and conditions set forth in this Agreement, and provided 
further that you agree you are responsible for the breach of this 
Agreement by any of your suppliers or contractors to the same extent 
that you would be if you breached the Agreement yourself.

c.	No Distribution License.  NOTWITHSTANDING ANYTHING TO THE 
CONTRARY, THIS AGREEMENT DOES NOT CONVEY ANY 
LICENSE TO DISTRIBUTE THE LICENSED MATERIALS TO ANY 
THIRD PARTY.  YOU ARE REQUIRED TO EXECUTE A SEPARATE 
LICENSE AGREEMENT WITH TI BEFORE DISTRIBUTING THE 
LICENSED MATERIALS OR ANY PRODUCTS THAT CONTAIN THE 
LICENSED MATERIALS, OR ANY DERIVATIVE THEREOF. 

	d.	Limited License to TI and Covenant not to Sue.  Continuing for the 
term of this Agreement, you hereby grant to TI under any of your 
patents embodied in the Licensed Materials a non-transferable, non-
exclusive, non-assignable, worldwide, fully paid-up, royalty-free license 
to make, use, sell, offer to sell, import, export and otherwise distribute 
such Licensed Materials.  You covenant not to sue or otherwise assert 
Derived Patents against TI and TI's affiliates and their licensees of the 
Licensed Materials.  In the event you assign a Derived Patent, you shall 
require as a condition of any such assignment that the assignee agree 
to be bound by the provisions in this Section 1(d) with respect to such 
Derived Patent.  Any attempted assignment or transfer in violation of 
this Section 1(d) shall be null and void.  For purposes of this Agreement, 
"Derived Patents" means any of your patents issuing from a patent 
application that discloses and claims an invention conceived of by you 
after delivery of the Licensed Materials, and derived by you from your 
access to the Licensed Materials. 

	e.	No Other License.  Notwithstanding anything to the contrary, nothing 
in this Agreement shall be construed as a license to any intellectual 
property rights of TI other than those rights embodied in the Licensed 
Materials provided to you by TI.  EXCEPT AS PROVIDED HEREIN, NO 
OTHER LICENSE, EXPRESS OR IMPLIED, BY ESTOPPEL OR 
OTHERWISE, TO ANY OTHER TI INTELLECTUAL PROPERTY 
RIGHTS IS GRANTED HEREIN.

	f.	Restrictions.  

i.	You shall not disclose or distribute the source code versions of 
the Licensed Materials, or any derivative thereof, to any person 
other than your employees and contractors whose job 
performance requires access.  

ii.	Use of any software application optimized or developed using 
the Licensed Materials on processing devices manufactured by 
or for an entity other than TI is a material breach of this 
Agreement.  Use of the Licensed Materials to assist in the 
design, development or verification of a device not manufactured 
by or for TI is a material breach of this Agreement.  Use of the 
Licensed Materials to evaluate, test, debug and optimize 
applications for use with processing devices other than those 
manufactured by or for TI is a material breach of this Agreement.  

iii.	Other than as expressly set forth in this Section 1(f)(iii) and in 
Section 1(a) above, you may not otherwise copy or reproduce 
the Licensed Materials.

iv.	You will not sublicense, transfer or assign the Licensed Materials 
or your rights under this Agreement to any third party.  

v.	You may use the Licensed Materials with Open Source Software 
(as defined below) or with software developed using Open 
Source Software (e.g. tools) provided you do not incorporate, 
combine or distribute the Licensed Materials in a manner that 
subjects the Licensed Materials, or any derivatives thereof, to 
any license obligations or any other intellectual property related 
terms of such Open Source Software.  "Open Source Software" 
means any software licensed under terms requiring that (A) other 
software ("Proprietary Software") incorporated, combined or 
distributed with such software or developed using such software: 
(i) be disclosed or distributed in source code form; or (ii) 
otherwise be licensed on terms inconsistent with the terms of this 
Agreement, including but not limited to permitting use of the 
Proprietary Software on or with devices other than TI Devices, or 
(B) the owner of Proprietary Software license any of its patents 
to users of the Open Source Software and/or Proprietary 
Software incorporated, combined or distributed with such Open 
Source Software or developed using such Open Source 
Software. 

	g.	Termination.  This Agreement is effective until terminated.  You may 
terminate this Agreement at any time by written notice to TI.  Without 
prejudice to any other rights, if you fail to comply with the terms of this 
Agreement, TI may terminate your right to use the Licensed Materials, 
or any derivative thereof, and any applications generated using the 
Licensed Materials, or any derivative thereof, upon written notice to you.  
Upon expiration or termination of this Agreement, you will destroy any 
and all copies of the Licensed Materials, including any derivatives 
thereof, in your possession, custody or control and provide to TI a 
written statement signed by your authorized representative certifying 
such destruction. Except for Sections 1(a) and 1(b) and the limited 
license to TI set forth in Section 1(d), all provisions of this Agreement 
shall survive expiration or termination of the Agreement.

2.	Licensed Materials Ownership.  The Licensed Materials are licensed, 
not sold to you, and can only be used in accordance with the terms of 
this Agreement.  Subject to the licenses granted to you pursuant to this 
Agreement, TI and TI's licensors own and shall continue to own all right, 
title and interest in and to the Licensed Materials, including all copies 
thereof.  The parties agree that all fixes, modifications and 
improvements to the Licensed Materials conceived of or made by TI 
that are based, either in whole or in part, on your feedback, suggestions 
or recommendations are the exclusive property of TI and all right, title 
and interest in and to such fixes, modifications or improvements to the 
Licensed Materials will vest solely in TI.  You acknowledge and agree 
that regardless of the changes made to the Licensed Materials, your 
right to use any and all derivatives of the Licensed Materials shall 
remain subject to the terms and conditions of this Agreement.  
Moreover, you acknowledge and agree that when your independently 
developed software or hardware components are combined, in whole or 
in part, with the Licensed Materials, or any derivative thereof, your right 
to use the Licensed Materials, or any derivative thereof, embodied in 
such resulting combined work shall remain subject to the terms and 
conditions of this Agreement.
	 
3.	Intellectual Property Rights.  

	a.	The Licensed Materials contain copyrighted material, trade secrets 
and other proprietary information of TI and its licensors and are 
protected by copyright laws, international copyright treaties and trade 
secret laws, as well as other intellectual property laws.  To protect TI's 
and its licensors' rights in the Licensed Materials, you agree, except as 
specifically permitted by statute by a provision that cannot be waived by 
contract, not to "unlock", decompile, reverse engineer, disassemble or 
otherwise translate any portions of the Licensed Materials provided to 
you in object code format only to a human-perceivable form nor to 
permit any person or entity to do so.  You shall not remove, erase, alter, 
tamper, cover or obscure any confidentiality, trade secret, proprietary or 
copyright notices, trade-marks, proprietary, patent or other identifying 
marks or designs printed or stamped on, affixed to, or encoded or 
recorded in any component of the Licensed Materials and you shall 
reproduce and include in all copies of the Licensed Materials the 
copyright notice(s) and proprietary legend(s) of TI and its licensors as 
they appear in the Licensed Materials.  TI reserves all rights not 
specifically granted under this Agreement.

	b.	Certain Licensed Materials may be based on industry recognized 
standards or software programs published by industry recognized 
standards bodies and certain third parties may claim to own patents, 
copyrights and other intellectual property rights that cover 
implementation of those standards.  You acknowledge and agree that 
this Agreement does not convey a license to any such third party 
patents, copyrights and other intellectual property rights and that you 
are solely responsible for any patent, copyright or other intellectual 
property right claim that relates to your use or distribution of the 
Licensed Materials, or your use or distribution of your products that 
include or incorporate the Licensed Materials.  Moreover, you 
acknowledge that any fees or royalties paid to TI pursuant to this 
Agreement, as applicable, do not include any fees or royalties that may 
be payable to any third party based on such third party's interests in the 
Licensed Materials or any intellectual property rights that cover 
implementation of any industry recognized standard, any software 
program published by any industry recognized standards bodies or any 
other proprietary technology.

4.	Audit Right.  At TI's request, and within thirty (30) days after receiving 
written notice, you shall permit an independent auditor selected by TI to 
have access, no more than once each calendar year (unless the 
immediately preceding audit revealed a breach of this Agreement) and 
during your regular business hours, to all of your equipment, records 
and documents as may contain information bearing upon the use of the 
Licensed Materials.  You shall keep full, complete, clear and accurate 
records with respect to product sales and distributions for a period 
beginning with the then-current calendar year and going back three (3) 
years.

5.	Confidential Information.  You acknowledge and agree that the 
Licensed Materials, and any derivative thereof, contain trade secrets 
and other confidential information of TI and its licensors.  You agree to 
use the Licensed Materials, or any derivative thereof, solely within the 
scope of the licenses set forth herein, to maintain the Licensed 
Materials, or any derivative thereof, in strict confidence, to use at least 
the same procedures and degree of care that you use to prevent 
disclosure of your own confidential information of like importance but in 
no instance less than reasonable care, and to prevent disclosure of the 
Licensed Materials, or any derivative thereof, to any third party, except 
as may be necessary and required in connection with your rights and 
obligations hereunder.  You agree to obtain executed confidentiality 
agreements with your employees and contractors having access to the 
Licensed Materials, or any derivative thereof, and to diligently take 
steps to enforce such agreements in this respect.  TI agrees that 
industry standard employment agreements used in the normal course of 
your business shall satisfy the requirements of this section. TI may 
disclose your contact information to TI's applicable licensors. 

6.	Warranties and Limitations.  THE LICENSED MATERIALS ARE 
PROVIDED "AS IS".  TI MAKES NO WARRANTY OR 
REPRESENTATION, EITHER EXPRESS, IMPLIED OR STATUTORY, 
REGARDING THE LICENSED MATERIALS, INCLUDING BUT NOT 
LIMITED TO, ANY IMPLIED WARRANTIES OF MERCHANTABILITY 
OR FITNESS FOR A PARTICULAR PURPOSE OR NON-
INFRINGEMENT OF ANY THIRD PARTY PATENTS, COPYRIGHTS, 
TRADE SECRETS OR OTHER INTELLECTUAL PROPERTY RIGHTS.  
YOU AGREE TO USE YOUR INDEPENDENT JUDGMENT IN 
DEVELOPING YOUR PRODUCTS AND DERIVATIVES OF THE 
LICENSED MATERIALS.  NOTHING CONTAINED IN THIS 
AGREEMENT WILL BE CONSTRUED AS A WARRANTY OR 
REPRESENTATION BY TI TO MAINTAIN PRODUCTION OF ANY TI 
SEMICONDUCTOR DEVICE OR OTHER HARDWARE OR 
SOFTWARE WITH WHICH THE LICENSED MATERIALS MAY BE 
USED.  

YOU ACKNOWLEDGE AND AGREE THAT THE LICENSED 
MATERIALS MAY NOT BE INTENDED FOR PRODUCTION 
APPLICATIONS AND MAY CONTAIN IRREGULARITIES AND 
DEFECTS NOT FOUND IN PRODUCTION SOFTWARE.  
FURTHERMORE, YOU ACKNOWLEDGE AND AGREE THAT THE 
LICENSED MATERIALS HAVE NOT BEEN TESTED OR CERTIFIED 
BY ANY GOVERNMENT AGENCY OR INDUSTRY REGULATORY 
ORGANIZATION OR ANY OTHER THIRD PARTY ORGANIZATION.  
YOU AGREE THAT PRIOR TO USING OR DISTRIBUTING ANY 
COMMERCIAL PRODUCT OPTIMIZED OR DEVELOPED USING THE 
LICENSED MATERIALS YOU WILL THOROUGHLY TEST THE 
PRODUCT AND THE FUNCTIONALITY OF THAT PRODUCT AND BE 
SOLELY RESPONSIBLE FOR ANY PROBLEMS OR FAILURES.

IN NO EVENT SHALL TI, OR ANY APPLICABLE LICENSOR, BE 
LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL, PUNITIVE OR 
CONSEQUENTIAL DAMAGES, HOWEVER CAUSED, ON ANY 
THEORY OF LIABILITY, IN CONNECTION WITH OR ARISING OUT 
OF THIS AGREEMENT OR THE USE OF THE LICENSED 
MATERIALS, OR ANY DERIVATIVE THEREOF, REGARDLESS OF 
WHETHER TI HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH 
DAMAGES.  EXCLUDED DAMAGES INCLUDE, BUT ARE NOT 
LIMITED TO, COST OF REMOVAL OR REINSTALLATION, OUTSIDE 
COMPUTER TIME, LABOR COSTS, LOSS OF DATA, LOSS OF 
GOODWILL, LOSS OF PROFITS, LOSS OF SAVINGS, OR LOSS OF 
USE OR INTERRUPTION OF BUSINESS.  IN NO EVENT WILL TI'S 
AGGREGATE LIABILITY UNDER THIS AGREEMENT OR ARISING 
OUT OF YOUR USE OF THE LICENSED MATERIALS, OR ANY 
DERIVATIVE THEREOF, EXCEED THE GREATER OF FIVE 
HUNDRED U.S. DOLLARS (US$500) OR THE FEES PAID TO TI BY 
YOU FOR THE LICENSED MATERIALS UNDER THIS AGREEMENT.

	Because some jurisdictions do not allow the exclusion or limitation of 
incidental or consequential damages or limitation on how long an 
implied warranty lasts, the above limitations or exclusions may not apply 
to you.

7.	Indemnification Disclaimer.  YOU ACKNOWLEDGE AND AGREE 
THAT TI SHALL NOT BE LIABLE FOR AND SHALL NOT DEFEND OR 
INDEMNIFY YOU AGAINST ANY THIRD PARTY INFRINGEMENT 
CLAIM THAT RELATES TO OR IS BASED ON YOUR 
MANUFACTURE, USE OR DISTRIBUTION OF THE LICENSED 
MATERIALS, OR ANY DERIVATIVE THEREOF, OR YOUR 
MANUFACTURE, USE, OFFER FOR SALE, SALE, IMPORTATION OR 
DISTRIBUTION OF YOUR PRODUCTS THAT INCLUDE OR 
INCORPORATE THE LICENSED MATERIALS, OR ANY DERIVATIVE 
THEREOF.

8.	No Technical Support.  TI and TI's licensors are under no obligation to 
install, maintain or support the Licensed Materials, or any derivatives 
thereof.  

9.	Notices.  All notices to TI hereunder shall be delivered to Texas 
Instruments Incorporated, 12500 TI Boulevard, Mail Station 8638, 
Dallas, Texas 75243, Attention: Contracts Manager, with a copy to 
Texas Instruments Incorporated, 13588 N. Central Expressway, Mail 
Station 3999, Dallas, Texas 75243, Attention: Law Department - ASP.  
All notices shall be deemed served when received by TI.

10.	Export Control.  You hereby acknowledge that the Licensed Materials 
are subject to export control under the U.S. Commerce Department's 
Export Administration Regulations ("EAR").  You further hereby 
acknowledge and agree that unless prior authorization is obtained from the 
U.S. Commerce Department, neither you nor your customers will export, 
re-export or release, directly or indirectly, any technology, software or 
software source code (as defined in Part 772 of the EAR), received from 
TI, or export, directly or indirectly, any direct product of such technology, 
software or software source code (as defined in Part 734 of the EAR), to 
any destination or country to which the export, re-export or release of the 
technology, software or software source code, or direct product is 
prohibited by the EAR.  You agree that none of the Licensed Materials 
may be downloaded or otherwise exported or reexported (i) into (or to a 
national or resident of) Cuba, Iran, North Korea, Sudan and Syria or any 
other country the U.S. has embargoed goods; or (ii) to anyone on the U.S. 
Treasury Department's List of Specially Designated Nationals or the U.S. 
Commerce Department's Denied Persons List or Entity List.  You 
represent and warrant that you are not located in, under the control of, or a 
national or resident of any such country or on any such list and you will not 
use or transfer the Licensed Materials for use in any sensitive nuclear, 
chemical or biological weapons, or missile technology end-uses unless 
authorized by the U.S. Government by regulation or specific license or for 
a military end-use in, or by any military entity of Albania, Armenia, 
Azerbaijan, Belarus, Cambodia, China, Georgia, Iraq, Kazakhstan, 
Kyrgyzstan, Laos, Libya, Macau, Moldova, Mongolia, Russia, Tajikistan, 
Turkmenistan, Ukraine, Uzbekistan and Vietnam. Any software export 
classification made by TI shall be for TI's internal use only and shall not 
be construed as a representation or warranty regarding the proper 
export classification for such software or whether an export license or 
other documentation is required for the exportation of such software.

11.	Governing Law and Severability.  This Agreement will be governed by 
and interpreted in accordance with the laws of the State of Texas, 
without reference to conflict of laws principles.  If for any reason a court 
of competent jurisdiction finds any provision of the Agreement to be 
unenforceable, that provision will be enforced to the maximum extent 
possible to effectuate the intent of the parties, and the remainder of the 
Agreement shall continue in full force and effect.  This Agreement shall 
not be governed by the United Nations Convention on Contracts for the 
International Sale of Goods, or by the Uniform Computer Information 
Transactions Act (UCITA).  The parties agree that non-exclusive 
jurisdiction for any dispute arising out of or relating to this Agreement 
lies within the courts located in the State of Texas.  Notwithstanding the 
foregoing, any judgment may be enforced in any United States or 
foreign court, and either party may seek injunctive relief in any United 
States or foreign court.

12.	PRC Provisions.  If you are located in the People's Republic of China 
("PRC") or if the Licensed Materials will be sent to the PRC, the 
following provisions shall apply and shall supersede any other 
provisions in this Agreement concerning the same subject matter:  

	a.	Registration Requirements.  You shall be solely responsible for 
performing all acts and obtaining all approvals that may be required in 
connection with this Agreement by the government of the PRC, 
including but not limited to registering pursuant to, and otherwise 
complying with, the PRC Measures on the Administration of Software 
Products, Management Regulations on Technology Import-Export, and 
Technology Import and Export Contract Registration Management 
Rules.  Upon receipt of such approvals from the government authorities, 
you shall forward evidence of all such approvals to TI for its records.  In 
the event that you fail to obtain any such approval or registration, you 
shall be solely responsible for any and all losses, damages or costs 
resulting therefrom, and shall indemnify TI for all such losses, damages 
or costs.

b.	Governing Language.  This Agreement is written and executed in 
the English language.  If a translation of this Agreement is required for 
any purpose, including but not limited to registration of the Agreement 
pursuant to any governmental laws, regulations or rules, you shall be 
solely responsible for creating such translation.  Any translation of this 
Agreement into a language other than English is intended solely in order 
to comply with such laws or for reference purposes, and the English 
language version shall be authoritative and controlling.

c.	Export Control.

i.	Diversions of Technology.  You hereby agree that unless 
prior authorization is obtained from the U.S. Department of 
Commerce, neither you nor your subsidiaries or affiliates shall 
knowingly export, re-export or release, directly or indirectly, any 
technology, software or software source code (as defined in Part 
772 of the Export Administration Regulations of the U.S. 
Department of Commerce ("EAR")), received from TI or any of its 
affiliated companies, or export, directly or indirectly, any direct 
product of such technology, software or software source code (as 
defined in Part 734 of the EAR), to any destination or country to 
which the export, re-export or release of the technology, software, 
software source code or direct product is prohibited by the EAR.

ii.	Assurance of Compliance.  You understand and 
acknowledge that products, technology (regardless of the form in 
which it is provided), software or software source code, received 
from TI or any of its affiliates under this Agreement may be under 
export control of the United States or other countries.  You shall 
comply with the United States and other applicable non-U.S. laws 
and regulations governing the export, re-export and release of any 
products, technology, software or software source code received 
under this Agreement from TI or its affiliates.  You shall not 
undertake any action that is prohibited by the EAR.  Without 
limiting the generality of the foregoing, you specifically agree that 
you shall not transfer or release products, technology, software or 
software source code of TI or its affiliates to, or for use by, military 
end users or for use in military, missile, nuclear, biological or 
chemical weapons end uses.
	
iii.	Licenses.  Each party shall secure at its own expense, such 
licenses and export and import documents as are necessary for 
each respective party to fulfill its obligations under this Agreement.  
If such licenses or government approvals cannot be obtained, TI 
may terminate this Agreement, or shall otherwise be excused from 
the performance of any obligations it may have under this 
Agreement for which the licenses or government approvals are 
required.

13.	Contingencies.	TI shall not be in breach of this Agreement and shall 
not be liable for any non-performance or delay in performance if such 
non-performance or delay is due to a force majeure event or other 
circumstances beyond TI's reasonable control, including but not limited 
to, shortages of labor, energy, fuel, machinery or materials, technical or 
yield failures, war, civil unrest, any government act, law or regulation, 
including any judicial order or decree, any communication or power 
failure, labor dispute, natural disaster, fire, flood, earthquake, explosion, 
terrorist act or Act of God.

14.	Entire Agreement.  This is the entire Agreement between you and TI 
and this Agreement supersedes any prior agreement between the 
parties related to the subject matter of this Agreement.  No amendment 
or modification of this Agreement will be effective unless in writing and 
signed by a duly authorized representative of TI.  You hereby warrant 
and represent that you have obtained all authorizations and other 
applicable consents required empowering you to enter into this 
Agreement.



		

Page 1

*/