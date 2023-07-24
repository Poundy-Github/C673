#ifdef VISUAL_C
//Setting for Visual Studio 2010
//special define for inline needed as C compiler does not know about it
	#ifdef inline
		#undef inline
	#endif
	#define inline __inline
#else
	#ifdef inline
		#undef inline
	#endif
	#define inline
#endif

#ifdef IOPT_MEMMAP_DATA
#undef IOPT_MEMMAP_DATA
#endif

#ifdef IOPT_MEMMAP_CODE
#undef IOPT_MEMMAP_CODE
#endif
