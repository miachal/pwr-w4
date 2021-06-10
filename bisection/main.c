/*
** Teoria Systemow
** Wyznaczanie pierwiastkow rownan i ekstremow metodami przyblizonymi
** x^3 - 12x^2 + 3x + 1 = 0
**
*/

#include <stdio.h>
#include <conio.h>

#define I_MAX 100000

double f(double x) {
   return x*x*x - 12*x*x + 3*x + 1;
}

int main(void) {
   double a,b,c,d,fc;
   int i=1,pp;

   printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"
          "++ Bisekcja                             | x^3 - 12x^2 + 3x + 1 = 0 ++\n"
          "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"
          "Przedzial [f,f]: ");
   scanf("%lf,%lf",&a,&b);

   printf("Dokladnosc [f]: "); scanf("%lf",&d);
   printf("Ilosc miejsc po przecinku [n]: "); scanf("%d",&pp);
   printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

   if(f(a)*f(b) < 0) {
      printf("[ k ]\t\t[ L ]\t\t[ P ]\t\txk\t\tf(xk)\n");
      for(;i<I_MAX;i++) {
         c = (a+b)/2;
         fc = f(c);

         printf("%5d  %14.*f %15.*f %12.*f %18.*f\n",i,pp,a,pp,b,pp,c,pp,fc);

         if(f(a) * fc < 0) b = c;
         else a = c;

         if((fc<0 ? -fc : fc) < d) {
            printf("\nRozwiazanie:\n   x0 = %.*f\n",pp,c);
            break;
         }
      }
   }
   else
      printf("[-] Funkcja musi przyjmowac na krancach przedzialu rozne znaki.\n");

   _getch();
   return 0;
}
