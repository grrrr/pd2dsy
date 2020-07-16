#define SAMPLE_RATE 48000.f

#include "daisy_boards.h"

// GENERATE INCLUDES START
// GENERATE INCLUDES END

using namespace daisy;

DSY_BOARD hardware;

Heavy_saw_test hv(SAMPLE_RATE);
int num_params;

// GENERATE GLOBALS START
// GENERATE GLOBALS END

void audiocallback(float *in, float *out, size_t size)
{
    for (int i = 0; i < num_params; i++)
    {
	HvParameterInfo info;
	hv.getParameterInfo(i, &info);
	hv.sendFloatToReceiver(info.hash, 0.f);
    }
    
    hv.processInlineInterleaved(in, out, size/2);	
    // GENERATE AUDIOCALLBACK START
    // GENERATE AUDIOCALLBACK END
}

int main(void)
{
    // GENERATE PREINIT START
    // GENERATE PREINIT END
    num_params = hv.getParameterInfo(0,NULL);
    
    if (DSY_BOARD == seed)
	hardware.Configure();
    hardware.Init();

    if (DSY_BOARD != seed)
	hardware.StartAdc();
    hardware.StartAudio(audiocallback);
    // GENERATE POSTINIT START
    // GENERATE POSTINIT END
    for(;;)
    {
        // GENERATE INFINITELOOP START
        // GENERATE INFINITELOOP END
    }
}
