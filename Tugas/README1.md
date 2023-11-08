1.glVertex2f= gl+Vertex + 2 +f(x,y)
glBegin(bidangnya);
glVertex2f();
glEnd();

# vertex tidak dapat berdiri sendiri

Bidang : titil,garis, dan gon(segitiga, segiempat, segilima...)
a.glBegin(GL_POINTS); // unutuk membuat titik
glVertex(0.0,0.0,0.0);
glEnd()

b. glBegin(GL_LINES); // untuk membuat garis
// syaratnya vertex harus berpasangan jumlah titik harus genap
glEnd()

C. glBegin(GL_TRIANGLES); // untuk membuat garis
// syaratnya vertex harus kelipatan 3

d. glBegin(GL_QUALS); // untuk membuat garis
// syaratnya vertex harus kelipatan 4

d. glBegin(GL_QUALS); // untuk membuat garis
// syaratnya vertex harus kelipatan 4
