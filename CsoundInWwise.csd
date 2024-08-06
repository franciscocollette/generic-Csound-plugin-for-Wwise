<CsoundSynthesizer>
<CsOptions>
-n
</CsOptions>
<CsInstruments>

sr = 44100
ksmps = 512
nchnls = 2
0dbfs = 1
/*
 //Possible channels to use: 
 //box 1 channels
chn_k "FaderA1", 3   // accepts values from 0 to 1
chn_k "FaderA2", 3	// accepts values from 0 to 1
chn_k "FaderA3", 3	// accepts values from -1 to 1
chn_k "FaderA4", 3	// accepts values from 0 to 1
chn_k "FaderA5", 3   // accepts values from -1 to 1
chn_k "CheckBox1", 3  // true/false values (1,0)
chn_k "CheckBox2", 3	 // true/false values (1,0)
chn_k "ComboBox1", 3	// int values from 0 to 4
 //box 2 channels
chn_k "FaderB1", 3   // accepts values from 0 to 1
chn_k "FaderB2", 3	// accepts values from 0 to 1
chn_k "FaderB3", 3	// accepts values from -1 to 1
chn_k "FaderB4", 3	// accepts values from 0 to 1
chn_k "FaderB5", 3   // accepts values from -1 to 1
chn_k "CheckBox3", 3  // true/false values (1,0)
chn_k "CheckBox4", 3	 // true/false values (1,0)
chn_k "ComboBox2", 3	// int values from 0 to 9
 //box 3 channels
chn_k "FaderC1", 3   // accepts values from 0 to 1
chn_k "FaderC2", 3	// accepts values from 0 to 1
chn_k "FaderC3", 3	// accepts values from -1 to 1
chn_k "FaderC4", 3	// accepts values from 0 to 1
chn_k "FaderC5", 3   // accepts values from -1 to 1
chn_k "CheckBox5", 3  // true/false values (1,0)
chn_k "CheckBox6", 3	 // true/false values (1,0)
chn_k "ComboBox3", 3	// int values from 0 to 14
 //box 4 channels
chn_k "FaderD1", 3   // accepts values from 0 to 1
chn_k "FaderD2", 3	// accepts values from 0 to 1
chn_k "FaderD3", 3	// accepts values from -1 to 1
chn_k "FaderD4", 3	// accepts values from 0 to 1
chn_k "FaderD5", 3   // accepts values from -1 to 1
chn_k "CheckBox7", 3  // true/false values (1,0)
chn_k "CheckBox8", 3	 // true/false values (1,0)
chn_k "ComboBox4", 3	// int values from 0 to 19
*/

gisine   ftgen 10, 0, 16384, 10, 1	;sine wave
giSawtooth ftgen 11,0, 2048, 10, 1, 0.5, 0.3, 0.25, 0.2 
gisaw    ftgen 12, 0, 16384, 10, 0, .2, 0, .4, 0, .6, 0, .8, 0,
1, 0, .8, 0, .6, 0, .4, 0,.2 
//giPulse   ftgen 52, 0, 128, 10, 1, 1, 1, 0.7, 0.5, 0.3, 0.1  
gisquare ftgen 13, 0, 16384, 10, 1, 0 , .33, 0, .2 , 0, .14, 0 , .11, 0, .09 ;odd harmonics
giPulse   ftgen 14, 0, 128, 10, 1, 1, 1, 0.7, 0.5, 0.3, 0.1  

instr 1
//just using a few of them
kamp chnget "FaderA1"
kfreq chnget "FaderA2"
kdistortEnable chnget "CheckBox1"
kdist chnget "FaderA3"
iwave chnget "ComboBox1"
iwave = iwave+10

kfreq = 10^(log10(20)+kfreq*(log10(20000)-log10(20))) // map the frequency range to 0-1 



a1 oscili 1, kfreq, iwave

if kdistortEnable == 1 then
a1 distort a1, kdist, -1
endif
outs a1*kamp, a1*kamp

endin



</CsInstruments>
<CsScore>
i1 0 z

</CsScore>
</CsoundSynthesizer>
