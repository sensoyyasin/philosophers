# Philosophers Dining Problem(Dying?)

--- ??爬 I never thought philosophy would be so deadly ??爬 ---

## ??喉?? Eat, Sleep, Spaghetti, repeat. This project is about learning how threads work by precisely timing a group of philosophers on when to pick up forks and eat spaghetti without dying from hunger.

Bilgisayar biliminde , yemek filozoflar覺 problemi , senkronizasyon sorunlar覺n覺 ve bunlar覺 癟繹zme tekniklerini g繹stermek i癟in e??zamanl覺 algoritma tasar覺m覺nda s覺kl覺kla kullan覺lan 繹rnek bir problemdir .

襤lk olarak 1965 y覺l覺nda Edsger Dijkstra taraf覺ndan teyp s羹r羹c羹s羹 癟evre birimlerine eri??im i癟in rekabet eden bilgisayarlar a癟覺s覺ndan sunulan bir 繹??renci s覺nav al覺??t覺rmas覺 olarak form羹le edilmi??tir. K覺sa bir s羹re sonra, Tony Hoare soruna mevcut ??eklini verdi.

<img width="300" alt="den" src="https://user-images.githubusercontent.com/73845925/188264079-3393ab33-6e34-4e20-ac4a-7f7c31a295d8.png">

# Genel Bak覺??

| Overview                                                                                                            |
| --------------------------------------------------------------------------------------------------------------------| 
| ??? Bir veya daha fazla filozof yuvarlak bir masada oturuyor. Masan覺n ortas覺nda b羹y羹k bir kase spagetti var.          |
| ??? Filozoflar yer, d羹??羹n羹r veya uyur.                                                                                |
| ??? Yemek yerken ne d羹??羹n羹rler ne de uyurlar; d羹??羹n羹rken yemek yemiyor ve uyumuyorlar;                                |
|   ve tabii ki uyurken yemek yemiyor ve d羹??羹nm羹yorlar.                                                               |
| ??? Masada 癟atallar da vard覺r. Filozoflar kadar 癟atallar vard覺r (n 癟atal n filozof).                                  |
| ??? Filozof yemek i癟in sa?? ve sol 癟atal覺 her iki eline birer tane al覺r.                                               |
| ??? Filozof yeme??ini bitirince 癟atal覺n覺 masaya koyar ve uyumaya ba??lar. Uyand覺??覺nda tekrar d羹??羹nmeye ba??lar.          |                                         
| ??? Bir filozof a癟l覺ktan 繹ld羹??羹nde program durur (starving).                                                          |
| ??? Her filozofun yemek yemesi gerekir ve asla a癟 kalmamal覺d覺r.                                                       |
| ??? Filozoflar ba??ka bir filozofun 繹lmek 羹zere olup olmad覺??覺n覺 bilmiyorlar.                                           |

# Kurallar

| Rules                                                                                                               |
| --------------------------------------------------------------------------------------------------------------------| 
| ??? number_of_philosophers : Filozoflar覺n say覺s覺 ve ayr覺ca 癟atallar覺n say覺s覺(n filozof =(?) n 癟atal).                 |
| ??? time_to_die (ms) : Bir filozofun a癟 kald覺??覺nda 繹lme s羹resi.                                                       |                                 
| ??? time_to_eat (ms) : Bir filozofun yemek yemesi i癟in ge癟en s羹re.                                                    |
| ??? time_to_sleep (ms) : Bir filozofun uyuyarak ge癟irece??i s羹re.                                                      |
| ??? Her filozofun 1'den sona kadar de??i??en bir numaras覺 vard覺r.                                                       |
| ??? 1 Numaral覺 filozofun oturdu??unu varsayal覺m.                                                                       |
| ??? N numaral覺 ba??ka herhangi bir filozof N-1 numaral覺 filozof ile N+1 numaral覺 filozof aras覺na oturur.               | 


# ???? Execute

Example: Without number_of_times_each_philosopher_must_eat Argument ./philo 4 500 200 200

Example: With number_of_times_each_philosopher_must_eat Argument ./philo 7 310 100 100 7

# ???儭? Compilation

Compiling The First Program (Mandatory Part): make philo/

![figure2](https://user-images.githubusercontent.com/73845925/188264076-d4a0dd94-4671-4d17-ba10-173e76844426.gif)
