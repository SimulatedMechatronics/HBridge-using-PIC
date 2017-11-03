#include "software.h"

int estado = 0;
int ativo = 0;

void main() {
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);
   enable_interrupts(GLOBAL);
   while(true) {
      if(input_b() != estado) {
         ativo = 1;
         estado = input_b();
      }
   
      if(ativo == 1){
         if(estado == 0) {
            output_a(1);
            delay_ms(5000);
            output_a(0);
         } else {
            output_a(2);
            delay_ms(5000);
            output_a(0);
         }
         ativo=0;
      }
   }
}
