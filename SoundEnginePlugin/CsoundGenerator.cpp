#include "CsoundGenerator.h"


#include "Generic_UI_for_CsoundSource.h"
#include "../Generic_UI_for_CsoundConfig.h"
#include <AK/AkWwiseSDKVersion.h>

CsoundGenerator* generator = nullptr;
unsigned int bufferSize = 512;
std::vector<double> bufferArray(bufferSize);
std::vector<double> samples(bufferSize);

AkUInt32 numberChanelsAtInit = 0;
AkUInt32 sampleRate = 0;

