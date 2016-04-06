import c4d
import random

particles = []

def main():
    objContainer = c4d.BaseObject(c4d.Onull)
    
    i = 0
    radius = 700
    for i in range(0, 10):
        p = c4d.BaseObject(c4d.Olight)
        #p[c4d.INSTANCEOBJECT_LINK] = instance
        #p[c4d.INSTANCEOBJECT_RENDERINSTANCE] = False
        print "brightness:", p[c4d.LIGHT_BRIGHTNESS]
        p[c4d.LIGHT_VLTYPE] = 1
        p[c4d.LIGHT_DETAILS_FALLOFF] = c4d.LIGHT_DETAILS_FALLOFF_INVERSESQUARE_CLAMPED
        p[c4d.LIGHT_DETAILS_OUTERDISTANCE] = 100
        p[c4d.LIGHT_VISIBILITY_OUTERDISTANCE] = 5
        print p[c4d.LIGHT_VISIBILITY_OUTERDISTANCE]
        
        x = random.uniform(-radius, radius)
        y = random.uniform(20, 300)
        z = random.uniform(-radius, radius)
        
        scale = random.uniform(1, 2);
        p.SetRelPos(c4d.Vector(x, y, z))
        p.SetRelScale(c4d.Vector(scale, scale, scale))
        p.InsertUnder(objContainer)
        particles.append(p)
        c4d.EventAdd()
        
    
    return objContainer
