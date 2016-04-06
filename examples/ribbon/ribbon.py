import c4d
import random
from OSC import OSCServer
import sys
from time import sleep
import threading

server = 0
st = 0
spheres = []

def initOSCServer(ip='localhost', port=8885) :
    global server, st
    server = OSCServer( (ip ,port) ) # basic
    server.addDefaultHandlers()
    print server
    
        
def startOSCServer() :
    print "Registered Callback-functions are :"
    for addr in server.getOSCAddressSpace():
        print addr
    st = threading.Thread( target = server.serve_forever )
    st.start()
    
def printing_handler(addr, tags, data, source):
    print "---"
##    print "received new osc msg from %s" % getUrlStr(source)
    print "with addr : %s" % addr
    print "typetags :%s" % tags
    print "the actual data is : %s" % data
    print "---"
    
def setOSCHandler(address="/print", hd=printing_handler) :
    server.addMsgHandler(address, hd) # adding our function
    
def checkcheckcheck(addr, tags, data, source):
    print "CHECK CHECK CHECK..."
    print "with addr : %s" % addr
    print "typetags :%s" % tags
    print "the actual data is : %s" % data
    
def updateParticlePosition(addr, tags, data, source) :
    scale = 100
    pos = c4d.Vector(data[0]*scale, data[1]*scale, data[2]*scale);
    index = int(data[3])
    sphere = spheres[index]
    sphere.SetRelPos(pos)
    
    
def onUpdate(addr, tags, data, source):
    c4d.EventAdd()

def closeOSC() :
    if server is not 0: server.close() 
    if st is not 0: st.join()
    
def exit():
    print "Exit program", server
    closeOSC();

def main():
    
    objNull = c4d.BaseObject(c4d.Onull);
    clone = op[c4d.ID_USERDATA, 1]
    
    print clone
    i = 0
    radius = 3
    for i in range(0, 1024):
        #sphere = c4d.BaseObject(c4d.Osphere)
        sphere = c4d.BaseObject(c4d.Oinstance)
        sphere[c4d.INSTANCEOBJECT_LINK] = clone
        sphere[c4d.INSTANCEOBJECT_RENDERINSTANCE] = True
        x = random.uniform(-radius, radius)
        y = random.uniform(-radius, radius)
        z = random.uniform(-radius, radius)
        s = 0.2;
        sphere.InsertUnder(objNull)
        sphere.SetRelPos(c4d.Vector(x, y, z))
        sphere.SetRelScale(c4d.Vector(s, s, s))
        spheres.append(sphere)
    
    print len(spheres)
    
    exit()
    initOSCServer()
    
    setOSCHandler('/check', checkcheckcheck)
    setOSCHandler('/positions', updateParticlePosition)
    setOSCHandler('/update', onUpdate)
    startOSCServer()
    
    return objNull

exit();