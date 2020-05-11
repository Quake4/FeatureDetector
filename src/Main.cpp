/* Main.cpp
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 04/17/2015
 * Last Modified    : 04/17/2015
 * 
 */

#include <iostream>
using std::cout;
using std::endl;

#include "x86/cpu_x86.h"
using namespace FeatureDetector;

void WriteFeature(bool feature, char* visual, bool &has)
{
	if (feature)
	{
		if (has) { cout << ", "; }
		cout << visual;
		has = true;
	}
}

int main(){

	// detect CPU features
	cpu_x86 features;
	features.detect_host();

	// output main CPU features
	cout << "Features: ";
	bool has = false;
	WriteFeature(features.HW_MMX, "MMX", has);
	WriteFeature(features.HW_SSE, "SSE", has);
	WriteFeature(features.HW_SSE2, "SSE2", has);
	WriteFeature(features.HW_SSE42, "SSE42", has);
	WriteFeature(features.HW_AES, "AES", has);
	WriteFeature(features.HW_SHA, "SHA", has);
	WriteFeature(features.HW_AVX && features.OS_AVX, "AVX", has);
	WriteFeature(features.HW_AVX2 && features.OS_AVX, "AVX2", has);
	WriteFeature(features.HW_VAES && features.OS_AVX, "VAES", has);
	WriteFeature(features.HW_AVX512_F && features.OS_AVX512, "AVX512", has);
	cout << endl;
}
