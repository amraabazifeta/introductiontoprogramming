#include <stdio.h>

int main(void)
{
    // Kullanıcın ismini saklamak için bir karakter dizisi (array) tanımlıyoruz
    // 50 karakterlik bir alan ayırdık
    char name[50];

    // Kullanıcıdan ismini iste
    printf("What is your name? ");

    // İsim almak için scanf kullanıyoruz. 
    // %s sadece ilk boşluğa kadar alır, eğer soyad da alınacaksa:
    // scanf("%[^\n]s", name); veya fgets(name, 50, stdin); kullanılabilir.
    scanf("%s", name);

    // Selamla
    printf("hello, %s\n", name);

    return 0;
}