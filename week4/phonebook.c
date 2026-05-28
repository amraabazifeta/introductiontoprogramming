//arda-portakal
#include <cs50.h>
#include <stdio.h>
#include <string.h>


typedef struct
{
    string name;
    string phone;
}
Person;

int main(void)
{
    Person people[5];

    people[0].name = "Ali";
    people[0].phone = "111-1111";

    people[1].name = "Ayse";
    people[1].phone = "222-2222";

    people[2].name = "Mehmet";
    people[2].phone = "333-3333";

string target = get_string("Name: ");

    // 4. Adım: Listede bu ismi ara
    // Biz yukarıda 3 kişi eklediğimiz için döngüyü 3 kere döndürüyoruz. Eğer listeyi 5 kişiye tamamlarsan burayı 5 yap.
    for (int i = 0; i < 3; i++)
    {
        // Eğer aradığımız isim (target) ile rehberdeki sıradaki isim (people[i].name) aynıysa (yani sonuç 0 çıkarsa)
        if (strcmp(people[i].name, target) == 0)
        {
            printf("%s\n", people[i].phone); // Numarayı ekrana yazdır
            return 0; // Kişiyi bulduk, işimiz bitti. Programı başarıyla sonlandır.
        }
    }

    // 5. Adım: Eğer üstteki döngü biter ve 'return 0' hiç çalışmazsa, demek ki kişi listede yok.
    printf("Not found\n");
    return 1;
}
