# Philosophers Dining Problem(Dying?)

--- I never thought philosophy would be so deadly ---

Bilgisayar biliminde , yemek filozofları problemi , senkronizasyon sorunlarını ve bunları çözme tekniklerini göstermek için eşzamanlı algoritma tasarımında sıklıkla kullanılan örnek bir problemdir .

İlk olarak 1965 yılında Edsger Dijkstra tarafından teyp sürücüsü çevre birimlerine erişim için rekabet eden bilgisayarlar açısından sunulan bir öğrenci sınav alıştırması olarak formüle edilmiştir. Kısa bir süre sonra, Tony Hoare soruna mevcut şeklini verdi.

<img width="300" alt="den" src="https://user-images.githubusercontent.com/73845925/188264079-3393ab33-6e34-4e20-ac4a-7f7c31a295d8.png">

# Genel Bakış

| Overview                                                                                                            |
| --------------------------------------------------------------------------------------------------------------------| 
| • Bir veya daha fazla filozof yuvarlak bir masada oturuyor. Masanın ortasında büyük bir kase spagetti var.          |
| • Filozoflar yer, düşünür veya uyur.                                                                                |
| • Yemek yerken ne düşünürler ne de uyurlar; düşünürken yemek yemiyor ve uyumuyorlar;                                |
|   ve tabii ki uyurken yemek yemiyor ve düşünmüyorlar.                                                               |
| • Masada çatallar da vardır. Filozoflar kadar çatallar vardır (n çatal n filozof).                                  |
| • Filozof yemek için sağ ve sol çatalı her iki eline birer tane alır.                                               |
| • Filozof yemeğini bitirince çatalını masaya koyar ve uyumaya başlar. Uyandığında tekrar düşünmeye başlar.          |                                         
| • Bir filozof açlıktan öldüğünde program durur (starving).                                                          |
| • Her filozofun yemek yemesi gerekir ve asla aç kalmamalıdır.                                                       |
| • Filozoflar başka bir filozofun ölmek üzere olup olmadığını bilmiyorlar.                                           |

# Kurallar

| Rules                                                                                                               |
| --------------------------------------------------------------------------------------------------------------------| 
| • number_of_philosophers : Filozofların sayısı ve ayrıca çatalların sayısı(n filozof =(?) n çatal).                 |
| • time_to_die (ms) : Bir filozofun aç kaldığında ölme süresi.                                                       |                                 
| • time_to_eat (ms) : Bir filozofun yemek yemesi için geçen süre.                                                    |
| • time_to_sleep (ms) : Bir filozofun uyuyarak geçireceği süre.                                                      |
                                                     |
                                                     |
                                                     v 
| • Her filozofun 1'den sona kadar değişen bir numarası vardır.                                                       |
| • 1 Numaralı filozofun oturduğunu varsayalım.                                                                       |
| • N numaralı başka herhangi bir filozof N-1 numaralı filozof ile N+1 numaralı filozof arasına oturur.               | 


![figure2](https://user-images.githubusercontent.com/73845925/188264076-d4a0dd94-4671-4d17-ba10-173e76844426.gif)
