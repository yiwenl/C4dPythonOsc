import c4d
import random
#Welcome to the world of Python


def exit() :
    print "END PROCESSS"
    
    
def main():
    
    objNull = c4d.BaseObject(c4d.Onull)
    
    i = 0
    
    cubes = []
    
    for i in range(0, 1000):
        radius = 1400
        o = c4d.BaseObject(c4d.Ocube)
        x = random.uniform(-radius, radius)
        y = random.uniform(-radius, radius)
        z = random.uniform(-radius, radius)
        sx = random.uniform(.25, 1)
        sy = random.uniform(.25, 1)
        sz = random.uniform(.25, 1)
        rx = random.uniform(0, 3.141592657 * 2)
        ry = random.uniform(0, 3.141592657 * 2)
        rz = random.uniform(0, 3.141592657 * 2)

        v = c4d.Vector(x, y, z)
        vs = c4d.Vector(sx, sy, sz)
        vr = c4d.Vector(rx, ry, rz)
        o.SetRelPos(v)
        o.SetRelScale(vs)
        o.SetRelRot(vr)
        o.InsertUnder(objNull)
        sName = "Cube" + str(i)
        o.SetName(sName)
        cubes.append(o)
        
      
    return objNull



exit()