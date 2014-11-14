// This header serves to smooth out the differences in FFmpeg and LibAV.

#ifdef USE_SWRESAMPLE

    #include <libswresample/swresample.h>

#else

    #include <libavresample/avresample.h>
    #include <libavutil/mathematics.h>

    #define SwrContext AVAudioResampleContext
    #define swr_init(ctx) avresample_open(ctx)
    #define swr_close(ctx) avresample_close(ctx)
    #define swr_free(ctx) avresample_free(ctx)
    #define swr_alloc() avresample_alloc_context()
    #define swr_get_delay(ctx, ...) avresample_get_delay(ctx)
    #define swr_convert(ctx, out, out_count, in, in_count) \
       avresample_convert(ctx, out, 0, out_count, (uint8_t **)in, 0, in_count)

#endif
