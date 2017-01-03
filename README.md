# memman
Memory manager

Count calls malloc(), realloc(), free(). Show class or function call this functions.

Use #define malloc() msvcore_memcon_malloc() or call interception for libraries. (I'm use for openssl).

Fast. Realtime. Opensource. Wonderful.

<pre>
Memory Control:
#Name                                       Alloc          Use         Free
class MString...................................5............5............0
                                 mem          239          239            0
CRYPTO_zalloc..................................12...........10............2
                                 mem          728          560          168
CRYPTO_malloc................................3144.........3071...........73
                                 mem       102057        99429         2628
class UList&lt;unsigned char,0,1,4096>.............1............0............1
                                 mem         4116            0         4116
CRYPTO_realloc.................................11............2............9
                                 mem        18396         9256         9140
All .........................................3173.........3088...........85
                                 mem       125536       109484        16052
MemCon use ................................129228.......127528.........1700
</pre>

Show call stack. Example:

AUF: Alloc / Use / Free. Counts. Mem: bytes.
<pre>
AUF: 1/1/0. MEM: 28/28/0. CRC: 1966608462
8: MString::StringNew - 0xDDA930
7: MString::MString - 0xDDAB40
6: main - 0xE18030
5: __tmainCRTStartup - 0xE1F7B0
4: mainCRTStartup - 0xE1F790
3: BaseThreadInitThunk - 0x75073398
2: RtlInitializeExceptionChain - 0x77509F0F
1: RtlInitializeExceptionChain - 0x77509F0F
0: RtlInitializeExceptionChain - 0x77509F0F
</pre>



Full output: http://pastebin.com/tiKkW4hz .
