import c4d
import random

def test() : 
	objNull = doc.SearchObject('Null')
	print objNull

	i = 0
	for i in range(0, 100):
		radius = 300
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
		print o.GetName()

		c4d.EventAdd()

test()