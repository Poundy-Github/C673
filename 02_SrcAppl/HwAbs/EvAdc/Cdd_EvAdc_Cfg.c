/**
 * \file Cdd_EvAdc_Cfg.c
 *
 * \brief 
 *
 * \version 
 * --------------------------------------------------------------------------------------------
 * Version	| 		Date		|		Author			| 	Comments
 * V0.0.1		2022.01.04			Xiong Yating			Init version
 * 
 * \copyright  2021 - 2022 Conti Smart Core
 *
 */
/*==================[inclusions]============================================*/
#include "Cdd_EvAdc_Cfg.h"

/*==================[external constants definition]=========================*/


/*==================[internal constants definition]=========================*/
#define EVADC_START_SEC_CORE0_QM_CONST
#include "EvAdc_MemMap.h"

const Adc_GroupType EvAdc_AdcGroupId0 = AdcConf_AdcGroup_AdcGroup_0;

const Adc_GroupType EvAdc_AdcGroupId2 = AdcConf_AdcGroup_AdcGroup_2;

const s_EvAdc_NtcType_t EvAdc_NtcTempTable[EVADC_NTC_TABLE_NUM]=
{
         {3896u	,-40}//-40degree
        ,{3885u	,-39}//-39degree
        ,{3873u	,-38}//-38degree
        ,{3862u	,-37}//-37degree
        ,{3849u	,-36}//-36degree
        ,{3836u	,-35}//-35degree
        ,{3823u	,-34}//-34degree
        ,{3809u	,-33}//-33degree
        ,{3794u	,-32}//-32degree
        ,{3779u	,-31}//-31degree
        ,{3763u	,-30}//-30degree
        ,{3747u	,-29}//-29degree
        ,{3730u	,-28}//-28degree
        ,{3712u	,-27}//-27degree
        ,{3694u	,-26}//-26degree
        ,{3675u	,-25}//-25degree
        ,{3656u	,-24}//-24degree
        ,{3636u	,-23}//-23degree
        ,{3615u	,-22}//-22degree
        ,{3594u	,-21}//-21degree
        ,{3572u	,-20}//-20degree
        ,{3549u	,-19}//-19degree
        ,{3526u	,-18}//-18degree
        ,{3501u	,-17}//-17degree
        ,{3477u	,-16}//-16degree
        ,{3457u	,-15}//-15degree
        ,{3426u	,-14}//-14degree
        ,{3399u	,-13}//-13degree
        ,{3372u	,-12}//-12degree
        ,{3344u	,-11}//-11degree
        ,{3315u	,-10}//-10degree
        ,{3286u	,-9}//-9degree
        ,{3256u	,-8}//-8degree
        ,{3225u	,-7}//-7degree
        ,{3194u	,-6}//-6degree
        ,{3162u	,-5}//-5degree
        ,{3130u	,-4}//-4degree
        ,{3097u	,-3}//-3degree
        ,{3063u	,-2}//-2degree
        ,{3029u	,-1}//-1degree
        ,{2995u	,0}//0degree
        ,{2960u	,1}//1degree
        ,{2925u	,2}//2degree
        ,{2889u	,3}//3degree
        ,{2853u	,4}//4degree
        ,{2816u	,5}//5degree
        ,{2779u	,6}//6degree
        ,{2742u	,7}//7degree
        ,{2704u	,8}//8degree
        ,{2667u	,9}//9degree
        ,{2629u	,10}//10degree
        ,{2590u	,11}//11degree
        ,{2552u	,12}//12degree
        ,{2513u	,13}//13degree
        ,{2474u	,14}//14degree
        ,{2435u	,15}//15degree
        ,{2396u	,16}//16degree
        ,{2357u	,17}//17degree
        ,{2318u	,18}//18degree
        ,{2279u	,19}//19degree
        ,{2240u	,20}//20degree
        ,{2202u	,21}//21degree
        ,{2163u	,22}//22degree
        ,{2124u	,23}//23degree
        ,{2086u	,24}//24degree
        ,{2048u ,25}//25degree
        ,{2009u	,26}//26degree
        ,{1971u	,27}//27degree
        ,{1934u	,28}//28degree
        ,{1896u	,29}//29degree
        ,{1859u	,30}//30degree
        ,{1822u	,31}//31degree
        ,{1786u	,32}//32degree
        ,{1750u	,33}//33degree
        ,{1714u	,34}//34degree
        ,{1679u	,35}//35degree
        ,{1644u	,36}//36degree
        ,{1609u	,37}//37degree
        ,{1575u	,38}//38degree
        ,{1542u	,39}//39degree
        ,{1509u	,40}//40degree
        ,{1476u	,41}//41degree
        ,{1444u	,42}//42degree
        ,{1412u	,43}//43degree
        ,{1381u	,44}//44degree
        ,{1350u	,45}//45degree
        ,{1319u	,46}//46degree
        ,{1290u	,47}//47degree
        ,{1260u	,48}//48degree
        ,{1232u	,49}//49degree
        ,{1203u	,50}//50degree
        ,{1175u	,51}//51degree
        ,{1148u	,52}//52degree
        ,{1121u	,53}//53degree
        ,{1095u	,54}//54degree
        ,{1070u	,55}//55degree
        ,{1044u	,56}//56degree
        ,{1020u	,57}//57degree
        ,{995u	,58}//58degree
        ,{972u	,59}//59degree
        ,{948u	,60}//60degree
        ,{926u	,61}//61degree
        ,{904u	,62}//62degree
        ,{883u	,63}//63degree
        ,{862u	,64}//64degree
        ,{841u	,65}//65degree
        ,{821u	,66}//66degree
        ,{802u	,67}//67degree
        ,{783u	,68}//68degree
        ,{764u	,69}//69degree
        ,{746u	,70}//70degree
        ,{728u	,71}//71degree
        ,{711u	,72}//72degree
        ,{694u	,73}//73degree
        ,{677u	,74}//74degree
        ,{661u	,75}//75degree
        ,{645u	,76}//76degree
        ,{630u	,77}//77degree
        ,{615u	,78}//78degree
        ,{600u	,79}//79degree
        ,{586u	,80}//80degree
        ,{572u	,81}//81degree
        ,{558u	,82}//82degree
        ,{545u	,83}//83degree
        ,{532u	,84}//84degree
        ,{519u	,85}//85degree
        ,{507u	,86}//86degree
        ,{495u	,87}//87degree
        ,{483u	,88}//88degree
        ,{472u	,89}//89degree
        ,{461u	,90}//90degree
        ,{450u	,91}//91degree
        ,{439u	,92}//92degree
        ,{429u	,93}//93degree
        ,{419u	,94}//94degree
        ,{409u	,95}//95degree
        ,{399u	,96}//96degree
        ,{390u	,97}//97degree
        ,{381u	,98}//98degree
        ,{372u	,99}//99degree
        ,{363u	,100}//100degree
        ,{355u	,101}//101degree
        ,{347u	,102}//102degree
        ,{339u	,103}//103degree
        ,{331u	,104}//104degree
        ,{324u	,105}//105degree
        ,{316u	,106}//106degree
        ,{309u	,107}//107degree
        ,{302u	,108}//108degree
        ,{295u	,109}//109degree
        ,{289u	,110}//110degree
        ,{282u	,111}//111degree
        ,{276u	,112}//112degree
        ,{270u	,113}//113degree
        ,{264u	,114}//114degree
        ,{258u	,115}//115degree
        ,{252u	,116}//116degree
        ,{246u	,117}//117degree
        ,{241u	,118}//118degree
        ,{236u	,119}//119degree
        ,{230u	,120}//120degree
        ,{225u	,121}//121degree
        ,{221u	,122}//122degree
        ,{216u	,123}//123degree
        ,{211u	,124}//124degree
        ,{207u	,125}//125degree
        ,{202u	,126}//126degree
        ,{198u	,127}//127degree
        ,{194u	,128}//128degree
        ,{189u	,129}//129degree
        ,{185u	,130}//130degree
        ,{181u	,131}//131degree
        ,{178u	,132}//132degree
        ,{174u	,133}//133degree
        ,{170u	,134}//134degree
        ,{167u	,135}//135degree
        ,{163u	,136}//136degree
        ,{160u	,137}//137degree
        ,{157u	,138}//138degree
        ,{153u	,139}//139degree
        ,{150u	,140}//140degree
        ,{147u	,141}//141degree
        ,{144u	,142}//142degree
        ,{141u	,143}//143degree
        ,{138u	,144}//144degree
        ,{136u	,145}//145degree
        ,{133u	,146}//146degree
        ,{130u	,147}//147degree
        ,{128u	,148}//148degree
        ,{125u	,149}//149degree
        ,{123u  ,150}//150degree
};

#define EVADC_STOP_SEC_CORE0_QM_CONST
#include "EvAdc_MemMap.h"

/*==================[external data definition]==============================*/


/*==================[internal data definition]==============================*/


/*==================[internal function declarations]========================*/



/*==================[external function definitions]=========================*/


/*==================[internal function definitions]=========================*/


