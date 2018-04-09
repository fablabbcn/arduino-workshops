int c = 0;
float size;

void setup() {
  size(800, 600);
  size = height/4;
  background(255, 255, 255);
}

void draw() {
  size = map(mouseX, 0, width, 0, width/4);
  println(size);
  if (c > width) c = 0;
  noStroke();
  background(255, 255, 255);
  fill(255, 0, 0, 100);
  rect(c, (height/2)-(size/2), size, size);
  fill(0, 255, 0, 100);
  ellipse(width-c, height/2, size, size);
  stroke(0, 0, 255);
  line(0, (height/2)+size, width, (height/2)+size);
  c++;
}