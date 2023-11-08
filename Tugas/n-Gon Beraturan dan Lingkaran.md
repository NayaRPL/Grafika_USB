# materi Strip, Line Loop, n-Gon Simetris

1. glLineStrip mengubungkan garis
   sama - sama meghubungkan gari
   <> Strup --> awal dan akhir tidak terhubung
2. glLineLoop mengubungkan garis
   sama - sama meghubungkan gari
   <> Loop --> awal dan akhir terhubung
3. n-gon simetris/ beraturan
   R = radius
   alfa = angel / sudutnya
   p = titik sudut --> glVertex
   yang harus diperhatikan adalah dalam menggambar itu
   dikombinasikan dengan GL_LINE_STrip/LOOP

   rumusnya :
   pi = (R cos(2phi*i/n)),R sin(2phi*i/n)
   i = sudut ke-...
   n = jumlah sudut
   glBegin(GL_LINE_STRIP);
   glVertex2f(titil pertama, titik kedua)
   glEnd()

   yang di tmabhkan di program
   #include <math.h>

   terdapat masalah jika kita ingin membuat segi yangbanyak misalkan 16 sudut , jika menggunakan secara manual akan tidak efektif oleh karena itu solusinya adalah membuat fungsi atau fungction

   # lingkaran merupakan segi banyak dan sudut yang tidak kelihat artinya jika menggunakan fungsi yang sebelumnya di buat itu maka nilai yang perlu di perhatikan adalah nilai seginya
