# CAN-BUS Send and Receive

Bu projede, Arduino ve MCP2515 CAN (Controller Area Network) modülü kullanarak bir CAN veri alışverişi örneği oluşturduk. CAN, araçlarda sıklıkla kullanılan bir iletişim protokolüdür ve birden çok cihazın birbirleriyle veri paylaşmasını sağlar. Bu proje, CAN protokolü hakkında fikir edinmek isteyenler için iyi bir öğrenme aracıdır.
<br><br>
Projede, bir veri paketi gönderip almayı gösterdim. Önce bir veri paketi hazırladım ve ardından MCP2515 modülü aracılığıyla CANBUS'a gönderdim. Daha sonra, aynı BUS üzerinden gelen veriyi okudum. Veri paketindeki mesaj formatını ve içeriğini okuyarak, bir cihazın diğerine nasıl veri gönderebileceği hakkında fikir edinebilirsiniz.
<br><br>
Projenin kodu oldukça basit ve anlaşılır. Arduino ve MCP2515 modülü arasında SPI arabirimini kullanarak iletişim kuruyoruz. Kodumuzda, CAN veri paketlerinin nasıl oluşturulup gönderileceği ve nasıl alınacağı adım adım açıklanıyor. Projeyi kendiniz de deneyerek, CAN protokolü hakkında daha fazla bilgi edinebilirsiniz.
<br><br>
Bu proje, araç içi uygulamalardan endüstriyel otomasyon sistemlerine kadar geniş bir yelpazede kullanılan CAN protokolü hakkında temel bilgiler sağlar. Ayrıca, Arduino ve MCP2515 modülü gibi ucuz ve yaygın olarak kullanılan bileşenleri kullanarak, projenin yapımı da oldukça kolaydır. Kendi projelerinizde CAN protokolünü kullanmak istiyorsanız, bu proje size iyi bir başlangıç noktası olabilir.
<br><br>
<h5>#CAN-BUS Send and Receive</h5>
Bu proje, MCP2515 kontrolcüsü kullanarak CAN-BUS veri yolu üzerinde mesaj gönderme ve alma işlevselliğini gösterir. Bu kod, Arduino ve MCP_CAN kütüphanesi kullanılarak yazılmıştır.
<br>
<h5>Nasıl Çalışır?</h5>
MCP2515 kontrolcüsü, Arduino'dan gelen verileri CAN-BUS veri yoluna yazar ve verileri okuyarak Arduino'ya geri gönderir. Bu kod, 14 baytlık bir veri dizisi oluşturarak bir mesaj gönderir ve ardından gelen mesajları okur.
<br>
<h5>Gereksinimler</h5>
Arduino Uno<br>
MCP2515 CAN-BUS kontrolcüsü<br>
MCP_CAN kütüphanesi<br>
<br>
<h5>Yükleme</h5>
Arduino IDE'de yeni bir proje açın.<br>
MCP_CAN kütüphanesini indirin ve Arduino IDE'de yükleyin.<br>
Bu kod örneğini kopyalayın ve Arduino IDE'de yeni bir dosyaya yapıştırın.<br>
Arduino Uno'yu bilgisayarınıza bağlayın ve kodu yükleyin.<br>
<br>
<h5>Geliştirme</h5>
Bu proje, MCP_CAN kütüphanesi ile başlangıç seviyesinde CAN-BUS programlama öğrenmek isteyenler için iyi bir kaynak olabilir. Projenin daha da geliştirilebilecek pek çok yönü var, örneğin:
<br> 
Farklı veri tipleri göndererek mesaj formatını çeşitlendirme<br>
İleri düzey bir hata ayıklama mekanizması ekleyerek kodu daha güvenilir hale getirme<br>
Bu kod örneğini farklı senaryolara uyacak şekilde kolayca özelleştirebilirsiniz.<br>
