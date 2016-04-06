/**
 * oscP5broadcastClient by andreas schlegel
 * an osc broadcast client.
 * an example for broadcast server is located in the oscP5broadcaster exmaple.
 * oscP5 website at http://www.sojamo.de/oscP5
 */

import oscP5.*;
import netP5.*;


OscP5 oscP5;
int PORT_OUTGOING = 8895;

/* a NetAddress contains the ip address and port number of a remote location in the network. */
NetAddress myBroadcastLocation; 

void setup() {
  size(400,400);
  frameRate(60);
  
  /* create a new instance of oscP5. 
   * 12000 is the port number you are listening for incoming osc messages.
   */
  oscP5 = new OscP5(this,12000);
  
  /* create a new NetAddress. a NetAddress is used when sending osc messages
   * with the oscP5.send method.
   */
  
  /* the address of the osc broadcast server */
  myBroadcastLocation = new NetAddress("127.0.0.1",PORT_OUTGOING);
}


void draw() {
  float x = mouseX/float(width) - 0.5f;
  float y = mouseY/float(height) - 0.5f;
  println("draw : " + x + "/" + y);
  background(0);
  
  OscMessage myOscMessage = new OscMessage("/test");
  myOscMessage.add(x * 500);
  myOscMessage.add(-y * 500);
  oscP5.send(myOscMessage, myBroadcastLocation);
}


void mousePressed() {
  println("mouse pressed, sending osc signal to port: " + PORT_OUTGOING);
  /* create a new OscMessage with an address pattern, in this case /test. */
  OscMessage myOscMessage = new OscMessage("/check");
  /* add a value (an integer) to the OscMessage */
  myOscMessage.add(100);
  myOscMessage.add(10);
  /* send the OscMessage to a remote location specified in myNetAddress */
  oscP5.send(myOscMessage, myBroadcastLocation);
}