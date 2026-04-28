#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Fonksiyon prototipleri
int count_letters(char text[]);
int count_words(char text[]);
int count_sentences(char text[]);

int main(void)
{
    char text[2000];

    // Kullanıcıdan metni al
    printf("Text: ");
    if (fgets(text, sizeof(text), stdin) == NULL)
    {
        return 1;
    }

    // Harf, kelime ve cümleleri say
    int letters   = count_letters(text);
    int words     = count_words(text);
    int sentences = count_sentences(text);

    // Eğer kelime sayısı 0 ise hata oluşmaması için kontrol
    if (words == 0) 
    {
        return 0;
    }

    // L ve S hesapla (float kullanarak hassas bölme yapıyoruz)
    float L = (float) letters / (float) words * 100.0;
    float S = (float) sentences / (float) words * 100.0;

    // Coleman-Liau Formülü
    float index_float = 0.0588 * L - 0.296 * S - 15.8;

    // YUVARLAMA HİLESİ: 
    // round() fonksiyonu yerine 0.5 ekleyip int'e çeviriyoruz.
    // Örn: 7.6 + 0.5 = 8.1 -> int yapınca 8 olur. (Matematik kütüphanesi gerektirmez)
    int index = (int) (index_float + 0.5);

    // Sonucu yazdır
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

    return 0;
}

// Harf sayan fonksiyon
int count_letters(char text[])
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

// Kelime sayan fonksiyon
int count_words(char text[])
{
    int count = 0;
    int n = strlen(text);
    if (n > 0 && !isspace(text[0])) count = 1;

    for (int i = 0; i < n; i++)
    {
        if (isspace(text[i]))
        {
            if (i > 0 && !isspace(text[i-1]) && text[i+1] != '\0' && text[i+1] != '\n')
            {
                count++;
            }
        }
    }
    return count;
}

// Cümle sayan fonksiyon
int count_sentences(char text[])
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}