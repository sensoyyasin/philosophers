# Philosophers Dining Problem(Dying?)

Bilgisayar biliminde , yemek filozofları problemi , senkronizasyon sorunlarını ve bunları çözme tekniklerini göstermek için eşzamanlı algoritma tasarımında sıklıkla kullanılan örnek bir problemdir .

İlk olarak 1965 yılında Edsger Dijkstra tarafından teyp sürücüsü çevre birimlerine erişim için rekabet eden bilgisayarlar açısından sunulan bir öğrenci sınav alıştırması olarak formüle edilmiştir. Kısa bir süre sonra, Tony Hoare soruna mevcut şeklini verdi.

<img width="320" alt="den" src="https://user-images.githubusercontent.com/73845925/188264079-3393ab33-6e34-4e20-ac4a-7f7c31a295d8.png">

# Genel Bakış

• Bir veya daha fazla filozof yuvarlak bir masada oturuyor.
Masanın ortasında büyük bir kase spagetti var.

• Filozoflar alternatif olarak yer, düşünür veya uyur.
Yemek yerken ne düşünürler ne de uyurlar; düşünürken yemek yemiyor ve uyumuyorlar;
ve tabii ki uyurken yemek yemiyor ve düşünmüyorlar.

• Masada çatallar da vardır. Filozoflar kadar çatal vardır(n çatal n filozof).
• Spagettiyi tek çatalla servis etmek ve yemek çok zahmetli olduğundan,
filozof yemek için sağ ve sol çatallarını her iki eline birer tane alır.

• Filozof yemeğini bitirince çatallarını masaya koyar ve uyumaya başlar. Uyandıklarında tekrar düşünmeye başlarlar. Bir filozof açlıktan öldüğünde simülasyon durur(starving).
• Her filozofun yemek yemesi gerekir ve asla aç kalmamalıdır.
• Filozoflar birbirleriyle konuşamazlar.
• Filozoflar başka bir filozofun ölmek üzere olup olmadığını bilmiyorlar.

![figure2](https://user-images.githubusercontent.com/73845925/188264076-d4a0dd94-4671-4d17-ba10-173e76844426.gif)
