//
//  GlobalSettings.hpp
//  ParticleTemplate
//
//  Created by Yi-Wen Lin on 2016/4/2.
//
//

#ifndef GlobalSettings_hpp
#define GlobalSettings_hpp

#include <stdio.h>

using namespace ci;
using namespace std;

class GlobalSettings {
    public :
    static GlobalSettings& getInstance() {
        static GlobalSettings settings;
        return settings;
    };
    
    int numParticles = 32;
    
    private :
    GlobalSettings() {};
};


#endif /* GlobalSettings_hpp */
