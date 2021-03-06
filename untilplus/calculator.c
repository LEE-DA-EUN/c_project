# include "cal.h"

NUM* plus(NUM *n1, NUM *n2){

  int carry = 0;
  NUM *ans = newNUM();
  numList *intpart = newNumList();
  numList *decimpart = newNumList();
  ans->integer = intpart;
  ans->decimal = decimpart;

  numNode *d1 = n1->decimal->head;
  numNode *d2 = n2->decimal->head;

  while(1){   //두수의 소수부분 자리수를 맞춰준다
    if(d1==NULL && d2==NULL) break;
    else if(d1==NULL){
      while(d2!=NULL){
        appendNum(n1->decimal, 0); d2 = d2->next;
      }
      break;
    }
    else if(d2==NULL){  //d2== NULL
      while(d1!=NULL){
        appendNum(n2->decimal, 0); d1 = d1->next;
      }
      break;
    }
    else{ //둘다 null X
      d1 = d1->next; d2 = d2->next;
    }
  } //prefect(debugging)

  numNode *dtail1 = getNumTail(n1->decimal);
  numNode *dtail2 = getNumTail(n2->decimal);

  while (dtail1 != NULL) {  //소수 부분 계산 시작
    int tmp = carry + dtail1->data + dtail2->data;
    if(tmp>9){
      carry = tmp/10; tmp = tmp%10;
      rappendNum(decimpart, tmp);
    }
    else{
      rappendNum(decimpart, tmp);  carry = 0;
    }
    dtail1 = dtail1->prev; dtail2 = dtail2->prev;
  }

  numNode *itail1 = getNumTail(n1->integer);
  numNode *itail2 = getNumTail(n2->integer);

  while(1){  // 정수부분 계산 시작
    if(itail1==NULL && itail2==NULL){
      break;
    }
    else if(itail1 == NULL){
        int tmp = carry + itail2->data;
        if(tmp>9){
          carry = tmp/10; tmp = tmp%10;
          rappendNum(intpart, tmp);
        }
        else {
          rappendNum(intpart, tmp); carry = 0;
        }
        itail2 = itail2->prev;
      }
      else if(itail2==NULL){ //itail2 == NULL
        int tmp = carry + itail1->data;
        if(tmp>9){
          carry = tmp/10; tmp = tmp%10;
          rappendNum(intpart, tmp);
        }
        else {
          rappendNum(intpart, tmp); carry = 0;
        }
        itail1 = itail1->prev;
      }
    else{ //둘다 널이 아닐 때
      int tmp = carry + itail1->data + itail2->data;
      if(tmp>9){
        carry = tmp/10; tmp = tmp%10;
        rappendNum(intpart, tmp);
      }
      else {
        rappendNum(intpart, tmp); carry = 0;
      }
      itail1 = itail1->prev; itail2= itail2->prev;
    }
  }
  if(carry != 0){
    rappendNum(intpart, carry);
  }
  return ans;
}

// --------------------- + ---------------------------------------

// NUM* minus(NUM *n1, NUM *n2){
//
// }
//
// NUM* multi(NUM *n1, NUM *n2){
//
// }
//
// NUM* divi(NUM *n1, NUM *n2){
//
// }

