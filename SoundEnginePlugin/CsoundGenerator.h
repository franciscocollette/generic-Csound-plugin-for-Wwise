#ifndef __CSOUNDGENERATOR_H__
#define __CSOUNDGENERATOR_H__

#include <csound.hpp>
#include <vector>
#include <string>

#include "Generic_UI_for_CsoundSource.h"
#include "../Generic_UI_for_CsoundConfig.h"
#include <AK/AkWwiseSDKVersion.h>

class CsoundGenerator {
    int cnt;
    Csound* csound;
    MYFLT* spout;
    int ksmps;
    int nchnls;

public:
    CsoundGenerator(const char* csdPath, AkUInt32 sampleRate) : cnt(0),
        csound(new Csound()),
        spout(NULL), ksmps(0),
        nchnls(1)
    {

        // compile instance of csound. IT NEEDS THE FULL PATH   "D:/maynooth/tesis/synth_csound_2/SoundEnginePlugin/synth_Test_csound_and_libsndfile.csd"
        std::string options = "--sample-rate=" + std::to_string(sampleRate);
        csound->Compile(csdPath, options.c_str());
        // do not put audio to soundcard
        csound->SetOption("-n");   // this option you have to put it manually in the .csd file and take out the -odac per default 
        // get ksmps value
        ksmps = csound->GetKsmps();
        // get nchnls value
        nchnls = csound->GetNchnls();
        // get spout pointer
        spout = csound->GetSpout();
        ksmps *= nchnls;
        //lets get channels
    };

    ~CsoundGenerator() {
        delete csound;
    }

    void setKChannel(const char* chnName, double value) {
        csound->SetControlChannel(chnName, value);
    }
    /* void muteCsound() {
         csound->SetOption("-n");
     }
    int getksamples() {
        return csound->GetKsmps();
    }*/

    // execute csound and fill buffer
    std::vector<double> execute(std::vector<double>& buf) {
        int32_t res = 0;
        for (int i = 0; i < buf.size(); i += 2) {
            if (cnt == 0) {
                res = csound->PerformKsmps();
                if (res) break;
            }
            buf[i] = spout[cnt++];
            if (nchnls > 1) buf[i + 1] = spout[cnt++]; // csound stereo
            else buf[i + 1] = buf[i]; // csound mono
            if (cnt == ksmps) cnt = 0;
        }
        return buf;
    }
};


extern CsoundGenerator* generator;
extern int kasamples;
extern unsigned int bufferSize;
extern std::vector<double> bufferArray;
extern std::vector<double> samples;
extern AkUInt32 sampleRate;




#endif

