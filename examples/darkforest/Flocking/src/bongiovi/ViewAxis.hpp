//
//  ViewAxis.hpp
//  BasicTemplate
//
//  Created by Yi-Wen Lin on 2016/4/1.
//
//

#ifndef ViewAxis_hpp
#define ViewAxis_hpp

#include <stdio.h>
#include "View.hpp"

using namespace bongiovi;

class ViewAxis : public View {
public:
    ViewAxis();
    ViewAxis(string vsPath, string fsPath);
    virtual void            render();
    
private:
    void                    _init();
};


#endif /* ViewAxis_hpp */
