#define PROJECTNAME "memman"
#define PROJECTVER PROJECTNAME ## _versions
#define USEMSV_MSVCORE

#define USEMSV_HASH
#define USEMSV_HTTP
#define USEMSV_CONSOLE

// #define USEMSV_MEMORYCONTROL - set as global
// #define USEMSV_INTERCEPT - set as global
#define USEMSV_MEMORYCONTROL_INFO // Add memory info
#define USEMSV_MEMORYCONTROL_STACK // Add stack trace


#define USEMSV_OPENSSL // Disable it if don't have openssl libraries


#include "msvcore2/msvcore.cpp"

Versions PROJECTVER[]={
	// new version to up
	"0.0.0.1", "01.01.2017 14:16"
};


class A{
public:
	void B(){
		free(malloc(1));
	}
};

DWORD S(LPVOID){
#ifdef USEMSV_OPENSSL
	SslGetUniqLine();
#endif
	return 1;
}

int main(int args, char* arg[], char* env[]){
	msvcoremain(args, arg, env);
	print(PROJECTNAME, " v.", PROJECTVER[0].ver," (", PROJECTVER[0].date, ").\r\n");

	// Print memory info
	MsvCoreMemoryControl.SetPrint(10);
	// Analog: MsvCoreMemoryControl.SetPrintFile(0, 10); // filename, timeout

	// Print stack to console
	MsvCoreMemoryControl.SetPrintStack(0, 30); // filename, timeout
	

	// Any memory operations //

	MString z = "3653463";

#ifdef USEMSV_OPENSSL
	SslGetUniqLine();
#endif

	StartThread(S);	

	LString ls;
	ls + 111;

	while(1){
		A a;
		a.B();

		Sleep(20);
	}

	return 0;
}

/* Memory info:
Memory Control:
#Name                                       Alloc          Use         Free
CRYPTO_zalloc................................2394...........17.........2377
                                 mem       189692         1232       188460
CRYPTO_malloc................................3608.........3071..........537
                                 mem       130321        38009        92312
CRYPTO_realloc.................................19............2...........17
                                 mem        22744         9216        13528
class UList<unsigned char,0,1,4096>.............2............1............1
                                 mem         8192         4096         4096
class MString...................................5............5............0
                                 mem          139          139            0
class ThreadStringCore..........................2............2............0
                                 mem       262128       262128            0
CRYPTO_clear_realloc...........................12............0...........12
                                 mem         5568            0         5568
operator new....................................1............0............1
                                 mem           12            0           12
class A......................................2128............1.........2127
                                 mem         2128            1         2127
All .........................................8171.........3099.........5072
                                 mem       620924       314821       306103
*/

/* Stack:
AUF: 1/0/1. MEM: 12/0/12. CRC: 1971850792
8: operator new - 0x12194F0
7: StartThread - 0x121AF50
6: main - 0x1246550
5: __tmainCRTStartup - 0x124C830
4: mainCRTStartup - 0x124C810
3: BaseThreadInitThunk - 0x758D3388
2: RtlInitializeExceptionChain - 0x77C79E6F
1: RtlInitializeExceptionChain - 0x77C79E6F
0: RtlInitializeExceptionChain - 0x77C79E6F

-- OR --

AUF: 1/0/1. MEM: 4096/0/4096. CRC: 1971896824
12: UList<unsigned char,0,1,4096>::AddBlock - 0x124A460
11: UList<unsigned char,0,1,4096>::Add - 0x1248980
10: LStringX<1>::add - 0x1248D10
9: LStringX<1>::operator+ - 0x12491D0
8: MsvCoreState::Main - 0x1229F90
7: msvcoremain - 0x122A760
6: main - 0x1246550
5: __tmainCRTStartup - 0x124C830
4: mainCRTStartup - 0x124C810
3: BaseThreadInitThunk - 0x758D3388
2: RtlInitializeExceptionChain - 0x77C79E6F
1: RtlInitializeExceptionChain - 0x77C79E6F
0: RtlInitializeExceptionChain - 0x77C79E6F

-- OR --

AUF: 12/10/2. MEM: 488/360/128. CRC: 2074065016
15: CRYPTO_zalloc - 0x12A1340
14: CRYPTO_THREAD_lock_new - 0x12A4850
13: ossl_init_base - 0x129FC50
12: ossl_init_base_ossl_ - 0x129FE90
11: CRYPTO_THREAD_run_once - 0x12A4930
10: OPENSSL_init_crypto - 0x129FEA0
9: OPENSSL_init_ssl - 0x1259220
8: MsvCoreActivateSsl::MsvCoreActivateSsl - 0x124B510
7: `dynamic initializer for 'MsvCoreActivateSsl'' - 0x13E8030
6: initterm - 0xF278670
5: __tmainCRTStartup - 0x124C830
4: mainCRTStartup - 0x124C810
3: BaseThreadInitThunk - 0x758D3388
2: RtlInitializeExceptionChain - 0x77C79E6F
1: RtlInitializeExceptionChain - 0x77C79E6F
0: RtlInitializeExceptionChain - 0x77C79E6F
*/