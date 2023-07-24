/*****************************************************************************/
/*                            CML Target Test Script                         */
/*****************************************************************************/
/*
*    Filename: test_cml_fourier.cpp
*    Author: uidp1547
*    Generated on: 19-Sep-2016 15:43:28
*/
/*****************************************************************************/
/* Environment Definition                                                    */
/*****************************************************************************/

/* Include files from software under test */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <float.h>
#include <math.h>

extern "C" {
#include "cml_ext.h"
}

/* The default value used for test script variables and stub returns*/
#define DEFAULT_VALUE 0
#define DELIMITER ','

#include "csv_parser.h"

#ifndef LINKED_LIST_PARSER
extern float data_log_buffer[1000000];
#endif

/* Test Log file */
extern FILE *fpTest;

//10*sin(2*pi*50*t) + 20*sin(2*pi*250*t) + 30*sin(2*pi*5000*t) + 40*sin(2*pi*550*t) + 50*sin(2*pi*25050*t);
const t_Complexf32 sinewave256[256] =
{
	{0	             ,	0,	},   
	{15.421776	     ,	0,	},
	{35.444729	     ,	0,	},
	{39.745159	     ,	0,	},
	{58.567188	     ,	0,	},
	{47.392292	     ,	0,	},
	{62.475487	     ,	0,	},
	{35.546875	     ,	0,	},
	{48.667507	     ,	0,	},
	{9.8505526	     ,	0,	},
	{26.180340	     ,	0,	},
	{-18.312033	     ,	0,	},
	{7.3354864	     ,	0,	},
	{-37.102455	     ,	0,	},
	{2.0425093	     ,	0,	},
	{-39.657745	     ,	0,	},
	{13.279041	     ,	0,	},
	{-27.167763	     ,	0,	},
	{35.818325	     ,	0,	},
	{-8.1950016	     ,	0,	},
	{58.778526	     ,	0,	},
	{5.4382515	     ,	0,	},
	{70.808426	     ,	0,	},
	{4.2901940	     ,	0,	},
	{65.510201	     ,	0,	},
	{-14.142136	     ,	0,	},
	{44.588951	     ,	0,	},
	{-44.060242	     ,	0,	},
	{17.262070	     ,	0,	},
	{-73.843300	     ,	0,	},
	{-3.8196602	     ,	0,	},
	{-91.248734	     ,	0,	},
	{-8.2825241	     ,	0,	},
	{-88.959999	     ,	0,	},
	{7.2393160	     ,	0,	},
	{-67.942017	     ,	0,	},
	{37.520588	     ,	0,	},
	{-37.064266	     ,	0,	},
	{71.039322	     ,	0,	},
	{-9.1577196	     ,	0,	},
	{95.105652	     ,	0,	},
	{4.6972041	     ,	0,	},
	{101.48639	     ,	0,	},
	{0.047582302	 ,	0,	},
	{89.963089	     ,	0,	},
	{-19.108019	     ,	0,	},
	{68.211967	     ,	0,	},
	{-42.364006	     ,	0,	},
	{48.082203	     ,	0,	},
	{-57.861725	     ,	0,	},
	{40	             ,	0,	},
	{-57.861725	     ,	0,	},
	{48.082203	     ,	0,	},
	{-42.364006	     ,	0,	},
	{68.211967	     ,	0,	},
	{-19.108019	     ,	0,	},
	{89.963089	     ,	0,	},
	{0.047582302	 ,	0,	},
	{101.48639	     ,	0,	},
	{4.6972041	     ,	0,	},
	{95.105652	     ,	0,	},
	{-9.1577196	     ,	0,	},
	{71.039322	     ,	0,	},
	{-37.064266	     ,	0,	},
	{37.520588	     ,	0,	},
	{-67.942017	     ,	0,	},
	{7.2393160	     ,	0,	},
	{-88.959999	     ,	0,	},
	{-8.2825241	     ,	0,	},
	{-91.248734	     ,	0,	},
	{-3.8196602	     ,	0,	},
	{-73.843300	     ,	0,	},
	{17.262070	     ,	0,	},
	{-44.060242	     ,	0,	},
	{44.588951	     ,	0,	},
	{-14.142136	     ,	0,	},
	{65.510201	     ,	0,	},
	{4.2901940	     ,	0,	},
	{70.808426	     ,	0,	},
	{5.4382515	     ,	0,	},
	{58.778526	     ,	0,	},
	{-8.1950016	     ,	0,	},
	{35.818325	     ,	0,	},
	{-27.167763	     ,	0,	},
	{13.279041	     ,	0,	},
	{-39.657745	     ,	0,	},
	{2.0425093	     ,	0,	},
	{-37.102455	     ,	0,	},
	{7.3354864	     ,	0,	},
	{-18.312033	     ,	0,	},
	{26.180340	     ,	0,	},
	{9.8505526	     ,	0,	},
	{48.667507	     ,	0,	},
	{35.546875	     ,	0,	},
	{62.475487	     ,	0,	},
	{47.392292	     ,	0,	},
	{58.567188	     ,	0,	},
	{39.745159	     ,	0,	},
	{35.444729	     ,	0,	},
	{15.421776	     ,	0,	},
	{2.8742833e-12	 ,	0,	},
	{-15.421776	     ,	0,	},
	{-35.444729	     ,	0,	},
	{-39.745159	     ,	0,	},
	{-58.567188	     ,	0,	},
	{-47.392292	     ,	0,	},
	{-62.475487	     ,	0,	},
	{-35.546875	     ,	0,	},
	{-48.667507	     ,	0,	},
	{-9.8505526	     ,	0,	},
	{-26.180340	     ,	0,	},
	{18.312033	     ,	0,	},
	{-7.3354864	     ,	0,	},
	{37.102455	     ,	0,	},
	{-2.0425093	     ,	0,	},
	{39.657745	     ,	0,	},
	{-13.279041	     ,	0,	},
	{27.167763	     ,	0,	},
	{-35.818325	     ,	0,	},
	{8.1950016	     ,	0,	},
	{-58.778526	     ,	0,	},
	{-5.4382515	     ,	0,	},
	{-70.808426	     ,	0,	},
	{-4.2901940	     ,	0,	},
	{-65.510201	     ,	0,	},
	{14.142136	     ,	0,	},
	{-44.588951	     ,	0,	},
	{44.060242	     ,	0,	},
	{-17.262070	     ,	0,	},
	{73.843300	     ,	0,	},
	{3.8196602	     ,	0,	},
	{91.248734	     ,	0,	},
	{8.2825241	     ,	0,	},
	{88.959999	     ,	0,	},
	{-7.2393160	     ,	0,	},
	{67.942017	     ,	0,	},
	{-37.520588	     ,	0,	},
	{37.064266	     ,	0,	},
	{-71.039322	     ,	0,	},
	{9.1577196	     ,	0,	},
	{-95.105652	     ,	0,	},
	{-4.6972041	     ,	0,	},
	{-101.48639	     ,	0,	},
	{-0.047582302	 ,	0,	},
	{-89.963089	     ,	0,	},
	{19.108019	     ,	0,	},
	{-68.211967	     ,	0,	},
	{42.364006	     ,	0,	},
	{-48.082203	     ,	0,	},
	{57.861725	     ,	0,	},
	{-40	         ,  0,	},
	{57.861725	     ,	0,	},
	{-48.082203	     ,	0,	},
	{42.364006	     ,	0,	},
	{-68.211967	     ,	0,	},
	{19.108019	     ,	0,	},
	{-89.963089	     ,	0,	},
	{-0.047582302	 ,	0,	},
	{-101.48639	     ,	0,	},
	{-4.6972041	     ,	0,	},
	{-95.105652	     ,	0,	},
	{9.1577196	     ,	0,	},
	{-71.039322	     ,	0,	},
	{37.064266	     ,	0,	},
	{-37.520588	     ,	0,	},
	{67.942017	     ,	0,	},
	{-7.2393160	     ,	0,	},
	{88.959999	     ,	0,	},
	{8.2825241	     ,	0,	},
	{91.248734	     ,	0,	},
	{3.8196602	     ,	0,	},
	{73.843300	     ,	0,	},
	{-17.262070	     ,	0,	},
	{44.060242	     ,	0,	},
	{-44.588951	     ,	0,	},
	{14.142136	     ,	0,	},
	{-65.510201	     ,	0,	},
	{-4.2901940	     ,	0,	},
	{-70.808426	     ,	0,	},
	{-5.4382515	     ,	0,	},
	{-58.778526	     ,	0,	},
	{8.1950016	     ,	0,	},
	{-35.818325	     ,	0,	},
	{27.167763	     ,	0,	},
	{-13.279041	     ,	0,	},
	{39.657745	     ,	0,	},
	{-2.0425093	     ,	0,	},
	{37.102455	     ,	0,	},
	{-7.3354864	     ,	0,	},
	{18.312033	     ,	0,	},
	{-26.180340	     ,	0,	},
	{-9.8505526	     ,	0,	},
	{-48.667507	     ,	0,	},
	{-35.546875	     ,	0,	},
	{-62.475487	     ,	0,	},
	{-47.392292	     ,	0,	},
	{-58.567188	     ,	0,	},
	{-39.745159	     ,	0,	},
	{-35.444729	     ,	0,	},
	{-15.421776	     ,	0,	},
	{-5.5128398e-12	 ,	0,	},
	{15.421776	     ,	0,	},
	{35.444729	     ,	0,	},
	{39.745159	     ,	0,	},
	{58.567188	     ,	0,	},
	{47.392292	     ,	0,	},
	{62.475487	     ,	0,	},
	{35.546875	     ,	0,	},
	{48.667507	     ,	0,	},
	{9.8505526	     ,	0,	},
	{26.180340	     ,	0,	},
	{-18.312033	     ,	0,	},
	{7.3354864	     ,	0,	},
	{-37.102455	     ,	0,	},
	{2.0425093	     ,	0,	},
	{-39.657745	     ,	0,	},
	{13.279041	     ,	0,	},
	{-27.167763	     ,	0,	},
	{35.818325	     ,	0,	},
	{-8.1950016	     ,	0,	},
	{58.778526	     ,	0,	},
	{5.4382515	     ,	0,	},
	{70.808426	     ,	0,	},
	{4.2901940	     ,	0,	},
	{65.510201	     ,	0,	},
	{-14.142136	     ,	0,	},
	{44.588951	     ,	0,	},
	{-44.060242	     ,	0,	},
	{17.262070	     ,	0,	},
	{-73.843300	     ,	0,	},
	{-3.8196602	     ,	0,	},
	{-91.248734	     ,	0,	},
	{-8.2825241	     ,	0,	},
	{-88.959999	     ,	0,	},
	{7.2393160	     ,	0,	},
	{-67.942017	     ,	0,	},
	{37.520588	     ,	0,	},
	{-37.064266	     ,	0,	},
	{71.039322	     ,	0,	},
	{-9.1577196	     ,	0,	},
	{95.105652	     ,	0,	},
	{4.6972041	     ,	0,	},
	{101.48639	     ,	0,	},
	{0.047582302	 ,	0,	},
	{89.963089	     ,	0,	},
	{-19.108019	     ,	0,	},
	{68.211967	     ,	0,	},
	{-42.364006	     ,	0,	},
	{48.082203	     ,	0,	},
	{-57.861725	     ,	0,	},
	{40	             ,	0,	},
	{-57.861725	     ,	0,	},
	{48.082203	     ,	0,	},
	{-42.364006	     ,	0,	},
	{68.211967	     ,	0,	},
	{-19.108019      ,	0	}
};

const t_Complexf32 sinewave16[16] =
{
	{0	             ,	0,	},   
	{15.421776	     ,	0,	},
	{35.444729	     ,	0,	},
	{39.745159	     ,	0,	},
	{58.567188	     ,	0,	},
	{47.392292	     ,	0,	},
	{62.475487	     ,	0,	},
	{35.546875	     ,	0,	},
	{48.667507	     ,	0,	},
	{9.8505526	     ,	0,	},
	{26.180340	     ,	0,	},
	{-18.312033	     ,	0,	},
	{7.3354864	     ,	0,	},
	{-37.102455	     ,	0,	},
	{2.0425093	     ,	0,	},
	{-39.657745	     ,	0 	}	
};

const t_Complexf32 sinewave16_2[16] =
{
	{0	                ,     0,},
	{-35.3333953851753	,     0,},
	{93.2476885096431	,     0,},
	{-87.9499949452489	,     0,},
	{150.165551401694	,     0,},
	{-94.9189769682221	,     0,},
	{150.655565376596	,     0,},
	{-50.2275131094596	,     0,},
	{99.6761331501955	,     0,},
	{27.4405406806025	,     0,},
	{24.6478623465458	,     0,},
	{103.025486621321	,     0,},
	{-37.3381822212992	,     0,},
	{141.051939025295	,     0,},
	{-56.6190001496450	,     0,},
	{121.916360494832   ,     0 }
};

//10*sin(2*pi*50*t) + 20*sin(2*pi*250*t) + 30*sin(2*pi*5000*t) + 40*sin(2*pi*550*t) + 50*sin(2*pi*25050*t);
const t_Complexf32 sinewave_after_fft256[256] =
{
	{576.50818          ,0                  , },
	{1174.3799          ,-643.26282         , },
	{-38.437439         ,304.16699          , },
	{179.97694          ,104.53497          , },
	{304.33887          ,15.936829          , },
	{534.90424          ,-88.983795         , },
	{1855.4629          ,-540.86572         , },
	{-1213.5842         ,436.63968          , },
	{-444.36578         ,167.77307          , },
	{-265.32043         ,89.300407          , },
	{-183.30518         ,38.031654          , },
	{-132.42059         ,-13.35479          , },
	{-89.69503          ,-88.816772         , },
	{-26.44379          ,-274.3183          , },
	{1153.3652          ,-4826.4795         , },
	{-206.2442          ,500.28589          , },
	{-141.57231         ,272.0954           , },
	{-117.58838         ,196.9469           , },
	{-103.94955         ,158.15738          , },
	{-94.770195         ,133.82118          , },
	{-88.032242         ,116.76907          , },
	{-82.821892         ,103.95042          , },
	{-78.651474         ,93.833405          , },
	{-75.23217          ,85.563156          , },
	{-72.374763         ,78.616142          , },
	{-69.952332         ,72.657997          , },
	{-67.876816         ,67.458542          , },
	{-66.076653         ,62.862003          , },
	{-64.505386         ,58.748344          , },
	{-63.123207         ,55.031059          , },
	{-61.899101         ,51.643414          , },
	{-60.809315         ,48.53125           , },
	{-59.836193         ,45.659119          , },
	{-58.961044         ,42.987808          , },
	{-58.171528         ,40.492317          , },
	{-57.456367         ,38.150257          , },
	{-56.807159         ,35.942177          , },
	{-56.215508         ,33.852703          , },
	{-55.6749           ,31.868052          , },
	{-55.179562         ,29.977882          , },
	{-54.724773         ,28.170399          , },
	{-54.306412         ,26.437893          , },
	{-53.920841         ,24.772648          , },
	{-53.564266         ,23.168121          , },
	{-53.23465          ,21.617855          , },
	{-52.929089         ,20.117046          , },
	{-52.646751         ,18.661869          , },
	{-52.38232          ,17.244286          , },
	{-52.136971         ,15.864709          , },
	{-51.908749         ,14.517838          , },
	{-51.698086         ,13.204239          , },
	{-51.498135         ,11.91095           , },
	{-51.313137         ,10.644381          , },
	{-51.140335         ,9.3994265          , },
	{-50.978867         ,8.1735573          , },
	{-50.828632         ,6.9647112          , },
	{-50.687916         ,5.7706079          , },
	{-50.556839         ,4.589047           , },
	{-50.43293          ,3.4212639          , },
	{-50.318905         ,2.25966            , },
	{-50.212315         ,1.1061392          , },
	{-50.112774         ,-0.041203499       , },
	{-50.019169         ,-1.1845336         , },
	{-49.940563         ,-2.3222318         , },
	{-49.856827         ,-3.4638541         , },
	{-49.783855         ,-4.6031189         , },
	{-49.716644         ,-5.7445569         , },
	{-49.654938         ,-6.8889871         , },
	{-49.598911         ,-8.0386009         , },
	{-49.548153         ,-9.194458          , },
	{-49.502361         ,-10.358324         , },
	{-49.462826         ,-11.531571         , },
	{-49.427158         ,-12.716162         , },
	{-49.396812         ,-13.913451         , },
	{-49.371574         ,-15.125472         , },
	{-49.351196         ,-16.353577         , },
	{-49.335949         ,-17.600296         , },
	{-49.325626         ,-18.867121         , },
	{-49.31995          ,-20.156927         , },
	{-49.321297         ,-21.470278         , },
	{-49.326469         ,-22.810682         , },
	{-49.337681         ,-24.180777         , },
	{-49.353653         ,-25.58333          , },
	{-49.377407         ,-27.019915         , },
	{-49.406841         ,-28.495146         , },
	{-49.442863         ,-30.011713         , },
	{-49.485863         ,-31.573284         , },
	{-49.537121         ,-33.184044         , },
	{-49.595654         ,-34.847946         , },
	{-49.663258         ,-36.569782         , },
	{-49.74028          ,-38.356049         , },
	{-49.827671         ,-40.209793         , },
	{-49.926373         ,-42.139599         , },
	{-50.037426         ,-44.151688         , },
	{-50.162868         ,-46.254246         , },
	{-50.296928         ,-48.453632         , },
	{-50.458046         ,-50.764797         , },
	{-50.633453         ,-53.195045         , },
	{-50.830402         ,-55.757729         , },
	{-51.051414         ,-58.467033         , },
	{-51.299782         ,-61.340118         , },
	{-51.579571         ,-64.394966         , },
	{-51.895584         ,-67.653534         , },
	{-52.254192         ,-71.140854         , },
	{-52.660797         ,-74.886246         , },
	{-53.125351         ,-78.924316         , },
	{-53.658051         ,-83.296127         , },
	{-54.272102         ,-88.049728         , },
	{-54.983849         ,-93.244888         , },
	{-55.814655         ,-98.95192          , },
	{-56.792328         ,-105.25824         , },
	{-57.950268         ,-112.27437         , },
	{-59.337193         ,-120.13229         , },
	{-61.016228         ,-129.01007         , },
	{-63.090698         ,-139.10669         , },
	{-65.639328         ,-150.78624         , },
	{-68.87973          ,-164.38936         , },
	{-73.063217         ,-180.48824         , },
	{-78.594757         ,-199.87637         , },
	{-86.126793         ,-223.72829         , },
	{-96.756088         ,-253.86142         , },
	{-112.47803         ,-293.27417         , },
	{-137.1994          ,-347.27383         , },
	{-179.62776         ,-426.5043          , },
	{-262.6803          ,-555.92114         , },
	{-467.67819         ,-814.41626         , },
	{-1358.1526         ,-1693.9756         , },
	{4802.8623          ,3134.8799          , },
	{1842.6903          ,0                  , },
	{4802.8643          ,-3134.9092         , },
	{-1358.1509         ,1693.9872          , },
	{-467.67657         ,814.42084          , },
	{-262.67975         ,555.92554          , },
	{-179.62744         ,426.50992          , },
	{-137.20239         ,347.28485          , },
	{-112.47339         ,293.27011          , },
	{-96.754501         ,253.86029          , },
	{-86.124069         ,223.72729          , },
	{-78.59417          ,199.87689          , },
	{-73.062088         ,180.48856          , },
	{-68.878578         ,164.39021          , },
	{-65.637466         ,150.78806          , },
	{-63.073059         ,139.12671          , },
	{-61.017357         ,129.00954          , },
	{-59.337704         ,120.13161          , },
	{-57.950226         ,112.27294          , },
	{-56.79071          ,105.25876          , },
	{-55.8144           ,98.951797          , },
	{-54.983795         ,93.244896          , },
	{-54.272022         ,88.04998           , },
	{-53.657974         ,83.296204          , },
	{-53.125099         ,78.924942          , },
	{-52.660881         ,74.886482          , },
	{-52.25391          ,71.141136          , },
	{-51.895363         ,67.653351          , },
	{-51.579353         ,64.395111          , },
	{-51.299698         ,61.340515          , },
	{-51.051323         ,58.467918          , },
	{-50.830055         ,55.759602          , },
	{-50.634998         ,53.190567          , },
	{-50.457874         ,50.764755          , },
	{-50.301414         ,48.454582          , },
	{-50.161358         ,46.253349          , },
	{-50.036644         ,44.150997          , },
	{-49.925888         ,42.139061          , },
	{-49.827301         ,40.209347          , },
	{-49.739834         ,38.35503           , },
	{-49.66283          ,36.570267          , },
	{-49.595379         ,34.847858          , },
	{-49.53643          ,33.183903          , },
	{-49.48592          ,31.573189          , },
	{-49.442616         ,30.011589          , },
	{-49.406639         ,28.495029          , },
	{-49.377247         ,27.019848          , },
	{-49.35463          ,25.582317          , },
	{-49.337498         ,24.180962          , },
	{-49.326027         ,22.810677          , },
	{-49.320194         ,21.470169          , },
	{-49.323399         ,20.154648          , },
	{-49.325611         ,18.866837          , },
	{-49.335819         ,17.600077          , },
	{-49.350975         ,16.353443          , },
	{-49.371201         ,15.125317          , },
	{-49.396389         ,13.913325          , },
	{-49.426617         ,12.715766          , },
	{-49.461288         ,11.530857          , },
	{-49.503899         ,10.358712          , },
	{-49.548313         ,9.1943808          , },
	{-49.598888         ,8.0383005          , },
	{-49.654797         ,6.8885241          , },
	{-49.716244         ,5.7431273          , },
	{-49.783558         ,4.6087308          , },
	{-49.856796         ,3.4638541          , },
	{-49.936115         ,2.3247983          , },
	{-50.021759         ,1.1844983          , },
	{-50.113777         ,0.041452885        , },
	{-50.21307          ,-1.1058078         , },
	{-50.319645         ,-2.2590327         , },
	{-50.433979         ,-3.4193702         , },
	{-50.556644         ,-4.5896749         , },
	{-50.687954         ,-5.7708836         , },
	{-50.828583         ,-6.9648294         , },
	{-50.979347         ,-8.1737833         , },
	{-51.140488         ,-9.3994293         , },
	{-51.313251         ,-10.644301         , },
	{-51.49818          ,-11.910681         , },
	{-51.695797         ,-13.200496         , },
	{-51.909508         ,-14.518156         , },
	{-52.137321         ,-15.865038         , },
	{-52.382381         ,-17.244806         , },
	{-52.644615         ,-18.658506         , },
	{-52.929111         ,-20.116827         , },
	{-53.234806         ,-21.617754         , },
	{-53.564522         ,-23.167967         , },
	{-53.920967         ,-24.772411         , },
	{-54.30682          ,-26.437759         , },
	{-54.725239         ,-28.170395         , },
	{-55.180546         ,-29.977697         , },
	{-55.673698         ,-31.868452         , },
	{-56.215176         ,-33.852661         , },
	{-56.807133         ,-35.942089         , },
	{-57.456577         ,-38.150024         , },
	{-58.172306         ,-40.491604         , },
	{-58.959198         ,-42.989376         , },
	{-59.836266         ,-45.659077         , },
	{-60.810387         ,-48.533112         , },
	{-61.899273         ,-51.643456         , },
	{-63.122749         ,-55.031029         , },
	{-64.504982         ,-58.748444         , },
	{-66.076225         ,-62.862213         , },
	{-67.875412         ,-67.459335         , },
	{-69.953163         ,-72.657028         , },
	{-72.374886         ,-78.615799         , },
	{-75.23201          ,-85.562561         , },
	{-78.652298         ,-93.834549         , },
	{-82.822075         ,-103.95033         , },
	{-88.032433         ,-116.76897         , },
	{-94.770584         ,-133.82109         , },
	{-103.95041         ,-158.16101         , },
	{-117.58876         ,-196.94615         , },
	{-141.57271         ,-272.09439         , },
	{-206.24518         ,-500.28363         , },
	{1153.3849          ,4826.457           , },
	{-26.442228         ,274.31683          , },
	{-89.69397          ,88.816193          , },
	{-132.41972         ,13.354767          , },
	{-183.30435         ,-38.031013         , },
	{-265.31961         ,-89.299911         , },
	{-444.36426         ,-167.77176         , },
	{-1213.5818         ,-436.63379         , },
	{1855.4602          ,540.85425          , },
	{534.90356          ,88.978912          , },
	{304.33893          ,-15.941254         , },
	{179.97733          ,-104.54065         , },
	{-38.437683         ,-304.17682         , },
	{1174.3835          ,643.28601            }
};

const t_Complexf32 sinewave_after_fft16[16] =
{	
	{293.59766  ,	0.00000000, },
	{-159.29926 ,	-263.12753, },
	{-24.703274 ,	-25.763617, },
	{-14.708249 ,	-18.126583, },
	{-11.572899 ,	-18.239908, },
	{-10.263474 ,	-22.023106, },
	{-9.7670794 ,	-31.549477, },
	{-10.399200 ,	-62.097260, },
	{187.82883  ,	0.00000000, },
	{-10.399055 , 	62.097198 , },
	{-9.7670555 , 	31.549471 , },
	{-10.263515 , 	22.023106 , },
	{-11.572884 , 	18.239908 , },
	{-14.708252 , 	18.126637 , },
	{-24.703251 , 	25.763622 , },
	{-159.29907 , 	263.12753   }
};

const t_Complexf32 sinewave2_after_fft16[16] =
{
	{549.44006  ,	0.00000000,},	
	{-79.470261 ,	101.76978 ,},	
	{-11.321591 ,	54.374710 ,},	
	{-1.3348053 ,	46.081623 ,},	
	{0.57141656 ,	48.524227 ,},	
	{-1.9019270 ,	61.219284 ,},	
	{-14.980833 ,	102.09267 ,},	
	{-315.99716 ,	866.92236 ,},	
	{299.43115 	,	0.00000000,},	
	{-315.99762 ,	-866.92249,},	
	{-14.980899 ,	-102.09267,},	
	{-1.9019043 ,	-61.219135,},	
	{0.57137519 ,	-48.524227,},	
	{-1.3346910 ,	-46.081558,},	
	{-11.321657 ,	-54.374710,},	
	{-79.470680 ,	-101.76990 }
};


#define MIN_VAL 1
#define MAX_VAL 10
#define STEP_SIZE_VAL 1
/* Global Functions */
extern float32 CML_f_AbsGen(float32 x);
extern float32 CML_f_MinGen(float32 x, float32 y);
extern float32 CML_f_MaxGen(float32 x, float32 y);
extern float32 CML_f_Round2FloatGen(float32 x);
extern sint32 CML_s_Round2IntGen(float32 x);
extern uint32 CML_u_Round2UintGen(float32 x);
extern float32 CML_f_Floor2FloatGen(float32 f_x);
extern float32 CML_f_Ceil2FloatGen(float32 f_x);
extern float32 CML_f_MultAddGen(float32 a, float32 b, float32 d);
extern sint32 CML_f_Sign(float32 f_Input);
extern float32 CML_f_PowToDB(float32 f_ratio);
extern float32 CML_f_MagToDB(float32 f_ratio);
extern CML_t_Matrix CML_a_InitMatrixHeader(uint32 u_ColNr, uint32 u_RowNr, float32* p_f_MtrxData);
extern void CML_v_FFT(t_Complexf32* a_Elements, const uint8 u_LogNofElements, boolean b_Inverse);
extern void CML_v_InverseFFT16(t_Complexf32* a_Elements);
float32 CML_f_SqrtApprox(float32 f_radicand);
float32 CML_f_fastlog10(float32 x);

/* Global data */
/* None */

/* Expected variables for global data */
/* None */

/* This function initialises global data to default values. This function       */
/* is called by every test case so must not contain test case specific settings */
static void initialise_global_data(){
  /* No global data */
}

/* This function copies the global data settings into expected variables for */
/* use in check_global_data(). It is called by every test case so must not   */
/* contain test case specific settings.                                      */
static void initialise_expected_global_data(){
   /* No global data */
}

/* This function checks global data against the expected values. */
static void check_global_data(){
    /* No global data */
}

/*****************************************************************************/
/* Test class declaration                                                    */
/*****************************************************************************/
class TEST_CLASS_CML_FOURIER
{
public:
	void run_tests_fourier();

	void test_CML_v_InverseFFT16(int);
	void test_CML_v_FFT(int);
};




/*****************************************************************************/
/* Program Entry Point                                                       */
/*****************************************************************************/
void test_cml_fourier(void)
{
	TEST_CLASS_CML_FOURIER test_object;

	std::cout << "******** Start Testing: CML Fast Fourier transform functions ********\n\n";
	fprintf(fpTest, "******** Start Testing: CML Fast Fourier transform functions ********\n\n");

	test_object.run_tests_fourier();

	std::cout << "End of Testing: CML Fast Fourier transform functions\n\n";
	fprintf(fpTest, "End of Testing: CML Fast Fourier transform functions\n\n");

	return;
}

/*****************************************************************************/
/* Test Control                                                              */
/*****************************************************************************/
void TEST_CLASS_CML_FOURIER::run_tests_fourier()
{	 
	 test_CML_v_FFT(1);    
	 test_CML_v_InverseFFT16(1);
}

/*****************************************************************************/
/* Test Cases                                                                */
/*****************************************************************************/
void TEST_CLASS_CML_FOURIER::test_CML_v_FFT(int doIt)
{
	if (doIt) 
	{

		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_CML_v_FFT_1   "test_001_CML_v_FFT_out_target.csv"	
		#define TEST_CML_VECTOR_CSVOUT_CML_v_FFT_2   "test_002_CML_v_FFT_out_target.csv"
		#define TEST_CML_VECTOR_CSVOUT_CML_v_FFT_3   "test_003_CML_v_FFT_out_target.csv"
		#define TEST_CML_VECTOR_CSVOUT_CML_v_FFT_4   "test_004_CML_v_FFT_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_v_FFT_1   "test_001_CML_v_FFT_out_msvc.csv"	
		#define TEST_CML_VECTOR_CSVOUT_CML_v_FFT_2   "test_002_CML_v_FFT_out_msvc.csv"	
		#define TEST_CML_VECTOR_CSVOUT_CML_v_FFT_3   "test_003_CML_v_FFT_out_msvc.csv"
		#define TEST_CML_VECTOR_CSVOUT_CML_v_FFT_4   "test_004_CML_v_FFT_out_msvc.csv"
#endif

		float32 f_power;
		float32 expected_returnValue;
		float32 returnValue;
		/* result CSV data, linked list node*/
#ifdef LINKED_LIST_PARSER
		csv_data_float_t *p_CsvDataOut = NULL;
#else
		csv_data_float_t p_CsvDataOut;
#endif

		csv_data_float_t *current_p_CsvDataOut = NULL;
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_v_FFT_1, "w+");	

		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;

		t_Complexf32	*p_Elements;
		uint8			u_LogNofElements;
	    boolean			b_Inverse;

		{
			/* Set global data */
    		initialise_global_data();
    		/* Set expected values for global data checks */
    		initialise_expected_global_data();

			/* **********************************************************************
			   *                         Test case 1                                *
			   ********************************************************************** */
								
#ifdef LINKED_LIST_PARSER
			{
				csv_data_float_t *temp_p_CsvDataOut = NULL;
				temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
				temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
				temp_p_CsvDataOut->len = sizeof(float32);

				*(temp_p_CsvDataOut->value) = CML_v_FFT(p_Elements, u_LogNofElements, b_Inverse);
			
				temp_p_CsvDataOut->next = NULL;

				counter++;
				if(p_CsvDataOut == NULL)
				{
					p_CsvDataOut = temp_p_CsvDataOut;				
					current_p_CsvDataOut = temp_p_CsvDataOut;
				}
				else
				{
					current_p_CsvDataOut->next = temp_p_CsvDataOut;
					current_p_CsvDataOut = current_p_CsvDataOut->next;
				}
				
			}
			/* parse CSV values for expected results */
			i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

			//printf("%d \t",counter);
			while(p_CsvDataOut != NULL)
			{
				csv_data_float_t *temp_p_CsvDataOut_free = NULL;
				temp_p_CsvDataOut_free = p_CsvDataOut;
				p_CsvDataOut = p_CsvDataOut->next;
				free(temp_p_CsvDataOut_free);
			}
#else
			int dataIndex = 0;

			/* Test FFT: N = 256 */
			{
				u_LogNofElements	= 8;
				b_Inverse			= FALSE;

				p_Elements = (t_Complexf32*)&data_log_buffer[10000];
			
				memcpy(p_Elements, sinewave256, sizeof(sinewave256));
									
				{
					p_CsvDataOut.value = data_log_buffer;
					p_CsvDataOut.len = sizeof(float32);			

					CML_v_FFT(p_Elements, u_LogNofElements, b_Inverse);	

					for (int i = 0; i < 256; i++)		
					{
						p_CsvDataOut.value[dataIndex++] = p_Elements[i].f_Real;
						p_CsvDataOut.value[dataIndex++] = p_Elements[i].f_Imag;
					}				
				}
			}
		

			p_CsvDataOut.dataBufferSize = dataIndex;

			/* parse CSV values for expected results */
			i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);

#endif

			fclose(fp);

			/* Checks on global data */
			check_global_data();			
		}

		{
			/* Set global data */
    		initialise_global_data();
    		/* Set expected values for global data checks */
    		initialise_expected_global_data();

			current_p_CsvDataOut = NULL;
			fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_v_FFT_2, "w+");

			/* **********************************************************************
			   *                         Test case 2                                *
			   ********************************************************************** */
								
#ifdef LINKED_LIST_PARSER
			{
				csv_data_float_t *temp_p_CsvDataOut = NULL;
				temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
				temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
				temp_p_CsvDataOut->len = sizeof(float32);

				*(temp_p_CsvDataOut->value) = CML_v_FFT(p_Elements, u_LogNofElements, b_Inverse);
			
				temp_p_CsvDataOut->next = NULL;

				counter++;
				if(p_CsvDataOut == NULL)
				{
					p_CsvDataOut = temp_p_CsvDataOut;				
					current_p_CsvDataOut = temp_p_CsvDataOut;
				}
				else
				{
					current_p_CsvDataOut->next = temp_p_CsvDataOut;
					current_p_CsvDataOut = current_p_CsvDataOut->next;
				}
				
			}
			/* parse CSV values for expected results */
			i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

			//printf("%d \t",counter);
			while(p_CsvDataOut != NULL)
			{
				csv_data_float_t *temp_p_CsvDataOut_free = NULL;
				temp_p_CsvDataOut_free = p_CsvDataOut;
				p_CsvDataOut = p_CsvDataOut->next;
				free(temp_p_CsvDataOut_free);
			}
#else
			int dataIndex = 0;

			/* Test FFT: N = 16 */
			{
				u_LogNofElements	= 4;
				b_Inverse			= FALSE;
			
				p_Elements = (t_Complexf32*)&data_log_buffer[10000];
			
				memcpy(p_Elements, sinewave16, sizeof(sinewave16));
									
				{
					p_CsvDataOut.value = data_log_buffer;
					p_CsvDataOut.len = sizeof(float32);			

					CML_v_FFT(p_Elements, u_LogNofElements, b_Inverse);	

					for (int i = 0; i < 16; i++)		
					{
						p_CsvDataOut.value[dataIndex++] = p_Elements[i].f_Real;
						p_CsvDataOut.value[dataIndex++] = p_Elements[i].f_Imag;
					}				
				}
			}
		

			p_CsvDataOut.dataBufferSize = dataIndex;

			/* parse CSV values for expected results */
			i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);

#endif

			fclose(fp);

			/* Checks on global data */
			check_global_data();			
		}

		{		

			/* **********************************************************************
			   *                         Test case 3                                *
			   ********************************************************************** */

			/* Set global data */
    		initialise_global_data();

    		/* Set expected values for global data checks */
    		initialise_expected_global_data();

			current_p_CsvDataOut = NULL;
			fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_v_FFT_3, "w+");
				
#ifdef LINKED_LIST_PARSER
			{
				csv_data_float_t *temp_p_CsvDataOut = NULL;
				temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
				temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
				temp_p_CsvDataOut->len = sizeof(float32);

				*(temp_p_CsvDataOut->value) = CML_v_FFT(p_Elements, u_LogNofElements, b_Inverse);
			
				temp_p_CsvDataOut->next = NULL;

				counter++;
				if(p_CsvDataOut == NULL)
				{
					p_CsvDataOut = temp_p_CsvDataOut;				
					current_p_CsvDataOut = temp_p_CsvDataOut;
				}
				else
				{
					current_p_CsvDataOut->next = temp_p_CsvDataOut;
					current_p_CsvDataOut = current_p_CsvDataOut->next;
				}
				
			}
			/* parse CSV values for expected results */
			i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

			//printf("%d \t",counter);
			while(p_CsvDataOut != NULL)
			{
				csv_data_float_t *temp_p_CsvDataOut_free = NULL;
				temp_p_CsvDataOut_free = p_CsvDataOut;
				p_CsvDataOut = p_CsvDataOut->next;
				free(temp_p_CsvDataOut_free);
			}
#else
			int dataIndex = 0;

			/* Test IFFT: N = 256 */
			{
				u_LogNofElements	= 8;
				b_Inverse			= TRUE;
							
				p_Elements = (t_Complexf32*)&data_log_buffer[10000];
			
				memcpy(p_Elements, sinewave_after_fft256, sizeof(sinewave_after_fft256));
									
				{
					p_CsvDataOut.value = data_log_buffer;
					p_CsvDataOut.len = sizeof(float32);			

					CML_v_FFT(p_Elements, u_LogNofElements, b_Inverse);	

					for (int i = 0; i < 256; i++)		
					{
						p_CsvDataOut.value[dataIndex++] = p_Elements[i].f_Real;
						p_CsvDataOut.value[dataIndex++] = p_Elements[i].f_Imag;
					}				
				}
			}
		

			p_CsvDataOut.dataBufferSize = dataIndex;

			/* parse CSV values for expected results */
			i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);

#endif

			fclose(fp);

			/* Checks on global data */
			check_global_data();			
			
		}	

		{		

			/* **********************************************************************
			   *                         Test case 3                                *
			   ********************************************************************** */

			/* Set global data */
    		initialise_global_data();

    		/* Set expected values for global data checks */
    		initialise_expected_global_data();

			current_p_CsvDataOut = NULL;
			fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_v_FFT_4, "w+");
				
#ifdef LINKED_LIST_PARSER
			{
				csv_data_float_t *temp_p_CsvDataOut = NULL;
				temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
				temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
				temp_p_CsvDataOut->len = sizeof(float32);

				*(temp_p_CsvDataOut->value) = CML_v_FFT(p_Elements, u_LogNofElements, b_Inverse);
			
				temp_p_CsvDataOut->next = NULL;

				counter++;
				if(p_CsvDataOut == NULL)
				{
					p_CsvDataOut = temp_p_CsvDataOut;				
					current_p_CsvDataOut = temp_p_CsvDataOut;
				}
				else
				{
					current_p_CsvDataOut->next = temp_p_CsvDataOut;
					current_p_CsvDataOut = current_p_CsvDataOut->next;
				}
				
			}
			/* parse CSV values for expected results */
			i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

			//printf("%d \t",counter);
			while(p_CsvDataOut != NULL)
			{
				csv_data_float_t *temp_p_CsvDataOut_free = NULL;
				temp_p_CsvDataOut_free = p_CsvDataOut;
				p_CsvDataOut = p_CsvDataOut->next;
				free(temp_p_CsvDataOut_free);
			}
#else
			int dataIndex = 0;

			/* Test IFFT: N = 16 */
			{
				u_LogNofElements	= 4;
				b_Inverse			= TRUE;
							
				p_Elements = (t_Complexf32*)&data_log_buffer[10000];
			
				memcpy(p_Elements, sinewave_after_fft16, sizeof(sinewave_after_fft16));
									
				{
					p_CsvDataOut.value = data_log_buffer;
					p_CsvDataOut.len = sizeof(float32);			

					CML_v_FFT(p_Elements, u_LogNofElements, b_Inverse);	

					for (int i = 0; i < 16; i++)		
					{
						p_CsvDataOut.value[dataIndex++] = p_Elements[i].f_Real;
						p_CsvDataOut.value[dataIndex++] = p_Elements[i].f_Imag;
					}				
				}
			}
		

			p_CsvDataOut.dataBufferSize = dataIndex;

			/* parse CSV values for expected results */
			i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);

#endif

			fclose(fp);

			/* Checks on global data */
			check_global_data();			
			
		}		
	}
}

void TEST_CLASS_CML_FOURIER::test_CML_v_InverseFFT16(int doIt)
{
	if (doIt) 
	{

		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_CML_v_InverseFFT16_1   "test_001_CML_v_InverseFFT16_out_target.csv"	
		#define TEST_CML_VECTOR_CSVOUT_CML_v_InverseFFT16_2   "test_002_CML_v_InverseFFT16_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_v_InverseFFT16_1   "test_001_CML_v_InverseFFT16_out_msvc.csv"
		#define TEST_CML_VECTOR_CSVOUT_CML_v_InverseFFT16_2   "test_002_CML_v_InverseFFT16_out_msvc.csv"
#endif

		float32 f_power;
		float32 expected_returnValue;
		float32 returnValue;
		/* result CSV data, linked list node*/
#ifdef LINKED_LIST_PARSER
		csv_data_float_t *p_CsvDataOut = NULL;
#else
		csv_data_float_t p_CsvDataOut;
#endif

		csv_data_float_t *current_p_CsvDataOut = NULL;
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_v_InverseFFT16_1, "w+");	

		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;

		t_Complexf32	*p_Elements;
		uint8			u_LogNofElements;
	    boolean			b_Inverse;

		{
			/* Set global data */
    		initialise_global_data();
    		/* Set expected values for global data checks */
    		initialise_expected_global_data();

			/* **********************************************************************
			   *                         Test case 1                                *
			   ********************************************************************** */
								
#ifdef LINKED_LIST_PARSER
			{
				csv_data_float_t *temp_p_CsvDataOut = NULL;
				temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
				temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
				temp_p_CsvDataOut->len = sizeof(float32);

				*(temp_p_CsvDataOut->value) = CML_v_InverseFFT16(p_Elements);
			
				temp_p_CsvDataOut->next = NULL;

				counter++;
				if(p_CsvDataOut == NULL)
				{
					p_CsvDataOut = temp_p_CsvDataOut;				
					current_p_CsvDataOut = temp_p_CsvDataOut;
				}
				else
				{
					current_p_CsvDataOut->next = temp_p_CsvDataOut;
					current_p_CsvDataOut = current_p_CsvDataOut->next;
				}
				
			}
			/* parse CSV values for expected results */
			i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

			//printf("%d \t",counter);
			while(p_CsvDataOut != NULL)
			{
				csv_data_float_t *temp_p_CsvDataOut_free = NULL;
				temp_p_CsvDataOut_free = p_CsvDataOut;
				p_CsvDataOut = p_CsvDataOut->next;
				free(temp_p_CsvDataOut_free);
			}
#else
			int dataIndex = 0;

			/* Test FFT: N = 16 */
			{					
				
				p_Elements = (t_Complexf32*)&data_log_buffer[10000];
			
				memcpy(p_Elements, sinewave_after_fft16, sizeof(sinewave_after_fft16));
									
				{
					p_CsvDataOut.value = data_log_buffer;
					p_CsvDataOut.len = sizeof(float32);			

					CML_v_InverseFFT16(p_Elements);

					for (int i = 0; i < 16; i++)		
					{
						p_CsvDataOut.value[dataIndex++] = p_Elements[i].f_Real;
						p_CsvDataOut.value[dataIndex++] = p_Elements[i].f_Imag;
					}				
				}
			}
		

			p_CsvDataOut.dataBufferSize = dataIndex;

			/* parse CSV values for expected results */
			i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);

#endif

			fclose(fp);

			/* Checks on global data */
			check_global_data();			
			
		}


		{		

			/* **********************************************************************
			   *                         Test case 2                                *
			   ********************************************************************** */

			/* Set global data */
    		initialise_global_data();

    		/* Set expected values for global data checks */
    		initialise_expected_global_data();

			current_p_CsvDataOut = NULL;
			fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_v_InverseFFT16_2, "w+");
				
#ifdef LINKED_LIST_PARSER
			{
				csv_data_float_t *temp_p_CsvDataOut = NULL;
				temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
				temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
				temp_p_CsvDataOut->len = sizeof(float32);

				*(temp_p_CsvDataOut->value) = CML_v_FFT(p_Elements, u_LogNofElements, b_Inverse);
			
				temp_p_CsvDataOut->next = NULL;

				counter++;
				if(p_CsvDataOut == NULL)
				{
					p_CsvDataOut = temp_p_CsvDataOut;				
					current_p_CsvDataOut = temp_p_CsvDataOut;
				}
				else
				{
					current_p_CsvDataOut->next = temp_p_CsvDataOut;
					current_p_CsvDataOut = current_p_CsvDataOut->next;
				}
				
			}
			/* parse CSV values for expected results */
			i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

			//printf("%d \t",counter);
			while(p_CsvDataOut != NULL)
			{
				csv_data_float_t *temp_p_CsvDataOut_free = NULL;
				temp_p_CsvDataOut_free = p_CsvDataOut;
				p_CsvDataOut = p_CsvDataOut->next;
				free(temp_p_CsvDataOut_free);
			}
#else
			int dataIndex = 0;

			/* Test IFFT: N = 16 */
			{							

				p_Elements = (t_Complexf32*)&data_log_buffer[10000];
			
				memcpy(p_Elements, sinewave2_after_fft16, sizeof(sinewave2_after_fft16));
									
				{
					p_CsvDataOut.value = data_log_buffer;
					p_CsvDataOut.len = sizeof(float32);			

					CML_v_InverseFFT16(p_Elements);

					for (int i = 0; i < 16; i++)		
					{
						p_CsvDataOut.value[dataIndex++] = p_Elements[i].f_Real;
						p_CsvDataOut.value[dataIndex++] = p_Elements[i].f_Imag;
					}				
				}
			}
		

			p_CsvDataOut.dataBufferSize = dataIndex;

			/* parse CSV values for expected results */
			i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);

#endif

			fclose(fp);

			/* Checks on global data */
			check_global_data();			
			
		}
	}
}

/*****************************************************************************/
/* End of test script                                                        */
/*****************************************************************************/
