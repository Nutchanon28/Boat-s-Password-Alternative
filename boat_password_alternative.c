// รหัสผ่านของพี่โบ๊ท
// พี่โบ๊ทเป็นคนที่มีความระมัดระวังตัวเองมากในการจดรหัสผ่านที่ตั้งไ้ว้ไม่ว่าจะเป็นรหัสโทรศัพท์ แท็บเลต หรือแม้แต่รหัสบัตร ATM
// พี่โบ๊ทจะจดไว้ในกระดาษเสมอแต่การจดของพี่โบ๊ทนั้นไม่ได้จดแบบธรรมดา ตัวอย่างการจดของพี่โบ๊ทเช่น รหัส 5555 พี่โบ๊ทจะจดไว้ว่า B710$H9&#36F54YO3512L568@666
// ก็คือการนำตัวเลขที่ถูกขั้นด้วยตัวอักษรหรือตัวอักษรพิเศษมารวมกันจะได้ 710+9+36+54+3512+568
// +666 จะเท่ากับ 5555 แต่บางครั้งพี่โบ๊ทก็ลืมรหัสแล้วต้องมานั่งบวกเองทุกครั้งทำให้เสียเวลาพี่โบ๊ทมาก
// พี่โบ๊ทเลยอยากให้น้องๆช่วยสร้างโปรแกรมสำหรับแก้รหัสผ่านที่พี่โบ๊ทจดไว้ให้พี่โบ๊ทหน่อย ขอร๊องงงง

// Specification
// Input
// บรรทัดที่ 1: รหัสที่ยังไม่ถูกแก้
// Output
// บรรทัดที่ 1: รหัสผ่าน 4 หลักที่ถูกแก้แล้ว หากไม่ถึง 4 หลักใ้ห้เติม 0 ข้างหน้าจนครบ 4 หลัก
// Sample Case
// Case 1
// 12BO01SS46

// 0059

// Case 2
// B&D259Y%9KM00

// 0268

// Case 3
// 64KM01001T$090

// 1155

#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    char input[10000];
    scanf("%s", &input);

    int sum = 0, number = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        if ((int)input[i] >= 48 && (int)input[i] <= 57)
        {
            number *= 10;
            number += (int)input[i] - 48;

            if (i != strlen(input) - 1)
            {
                continue;
            }
        }

        sum += number;
        number = 0;
    }

    int digit;
    for (int i = 3; i >= 0; i--)
    {
        digit = pow(10, i);
        // Because of integer truncation. pow() returns a floating point value,
        // and due to floating point arithmetic, it is probably ~ 99.999...;
        // however, due to integer truncation, even 99.999... gets truncated down to 99.
        if (digit % 10 != 0 && digit != 1)
        {
            digit += 1;
        }

        printf("%d", sum / digit);
        sum %= digit;

        // This doesn't work, and I don't know why.
        // printf("%d", sum / pow(10, i));
    }
}