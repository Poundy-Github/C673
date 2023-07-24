/*~-*/
/*~XSF_LANGUAGE: C/C++*/
/*~A*/
/*~+:Module Header*/
/*~T*/
/**************************************************************************
                                                                           
COPYRIGHT (C) $Date: 2017/03/28 21:14:43CEST $                              
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $                                
ALL RIGHTS RESERVED.                                                       
                                                                           
The reproduction, transmission or use of this document or its contents is  
not permitted without express written authority.                           
Offenders will be liable for damages. All rights, including rights created 
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------

Spec Reference:
Purpose: Automated Code Generation specific configuration for PC-Lint
         Must be included on beginning of the .c module (ACG)


$ProjectName: /ADAS/SW/Projects/MFC431x/MFC431XXXX/DPU/04_Engineering/01_Source_Code/LCF/Common/SDA/project.pj $

$Log: lintopt_acg.h  $
Revision 1.1 2017/03/28 21:14:43CEST uid41806 
Initial revision
Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/Common/SDA/project.pj
Revision 1.0 2017/02/01 13:33:30CET Prajescu, Claudia (uidl9533) 
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/algo/lcf/RTW_Common/SDA/project.pj
Revision 1.2 2013/07/30 12:45:49CEST Garrelfs Ralf-Ingo (uidg0598) (uidg0598) 
RO-497745-1:Usage of original SW lint configuration
Revision 1.2 2013/02/22 16:34:42CET Shetti Sujeet (uidv7505) (uidv7505) 
Switch off messages 503,504,514,551,568,571,578,681,715,775,942 in lintopt_acg.h
Switch off Sub-messages 8.5, 10.4, 10.5. 12.4, 12.10, 19.1 under message 960 in lintopt_acg.h
Revision 1.1 2011/01/31 11:46:24CET Kalz Andreas (uid08536) (uid08536) 
Initial revision
Member added to project /ES/FS/0A/config/lint/pi/project.pj
****************************************************************************/

/*~E*/
/*~A*/
/*~+:Lint Commands*/
/*~T*/
/*lint -e525 */   /* Negative indentation from line xxx */
/*lint -e539 */   /* Did not expect positive indentation from line xxx */
/*lint -e550 */   /* Symbol XXX not accessed G.5*/
/*lint -e621 */   /* Identifier clash A.3*/
/*lint -e685 */   /* Relational operator '>=' always evaluates to 'true' */
/*lint -e731 */   /* Boolean argument to equal/not equal D.19, D.20*/
/*lint -e734 */   /* Loss of precision (assignment) D.19, D.20 */
/*lint -e750 */   /* local macro XXX not referenced G.5 */
/*lint -e760 */   /* Redundant macro 'XXXX' defined identically at line nnn */
/*lint -e766 */   /* Header file XXX not used in module YYY D.10 */
/*lint -e774 */   /* Boolean within 'if' always evaluates to False G.5 */

/*New Changes (15-01-13)*/
/*lint -e503 */   /* Boolean argument to relational */
/*lint -e504 */   /* Unusual shift operation (String) */
/*lint -e514 */   /* It is only unusual and not wrong */
/*lint -e551 */   /* Symbol 'Symbol' (Location) not accessed */
/*lint -e568 */   /* non negative quantity is never less than zero */
/*lint -e571 */   /* Suspicious cast: This is strange but not wrong.*/
/*lint -e578 */   /* This only affects the readability, but correct in 	C */
/*lint -e681 */   /* Loop is not entered */
/*lint -e715 */   /* This is caused by our configuration & happens quite often in generic code. */
/*lint -e775 */   /* non-negative quantity cannot be less than zero */
/*lint -e942 */   /* Possibly truncated addition promoted to float: Not critical */

/*lint -esym(960,8.5)   */   /* No definitions of objects or function in header files. */
/*lint -esym(960,10.4)  */   /* Prohibited cast of complex expressions */
/*lint -esym(960,10.5)  */   /* Recasting required for operators '~' and '<<' */
/*lint -esym(960,12.4)  */   /* Side effects on right hand side of logical operator. */ 
/*lint -esym(960,12.10) */   /* Comma operator used outside of 'for' expression */
/*lint -esym(960,19.1)  */   /* Only preprocessor statements & comments before '#include'*/

/*~E*/
