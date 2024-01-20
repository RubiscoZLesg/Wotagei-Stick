# 可变色充电式电子荧光棒
WOTA艺打师永業参上！ 骗个关注先~ \
https://space.bilibili.com/18416307?spm_id_from=333.1007.0.0 \
因为目前市面上可充电电棒各有千秋（参差不齐），不是很符合个人平时练习需求，于是就自己做了个。 \
成本相当低廉，外壳使用了外径18mm，壁厚1.5mm，长20cm的透明PC管，PCB与3D打印零件均由嘉立创打样制作，如果领了券的话，一对大概能以20元价格拿下。 \
另外为了脱机控制颜色，制作了控制板，成本大概在5元左右，界面不甚优雅，突出一个能用就行。

## 光棒
主控采用了STC8G，驱动12颗WS2812灯珠，供电采用单节14500电池，长按开关机。为防止误触与增加稳定性，开关做在了顶部，但尺寸选的不太好（手里有于是就没买别的） \
为了保存颜色，MCU一旦上电就不会掉电，但整板采用了低功耗设计，静态功耗在uA级，充满电后也可以连续正常使用2小时以上。

- 光棒效果
<img src="https://github.com/RubiscoZLesg/Wotagei-Stick/blob/main/Image/stick.jpg" width="400">

- 充电效果
<img src="https://github.com/RubiscoZLesg/Wotagei-Stick/blob/main/Image/charging.jpg" width="400">

- 灯板正反面
<img src="https://github.com/RubiscoZLesg/Wotagei-Stick/blob/main/Image/stick_board.jpg" width="400">

## 控制板
主控采用了STM32G030，带一块0.96寸IPS，颜色控制数据传输采用了串口（USB两个数据线一根TX一根RX）,也是能充电的。

- 正面长这样
<img src="https://github.com/RubiscoZLesg/Wotagei-Stick/blob/main/Image/controller_front.jpg" width="400">

- 背面长这样（TYPE-A座子再插TYPE-C线属实不够优雅，但手头刚好有而且好焊）
<img src="https://github.com/RubiscoZLesg/Wotagei-Stick/blob/main/Image/controller_back.jpg" width="400">

- 屏幕界面
<img src="https://github.com/RubiscoZLesg/Wotagei-Stick/blob/main/Image/screen.jpg" width="400">

## 制作方法
Gerber文件夹中有各个部分的Gerber文件，交付板厂就能直接打样，光棒灯板板厚要选`1.0mm`。 \
Model文件夹中是外壳零件的STL文件，可直接3D打印。 \
Frimware文件夹中是光棒的hex固件，使用`STC-ISP`烧录。 \
Hardware文件夹中提供了立创EDA与AD（立创EDA导出的hh）两种PCB工程文件，方便各位查看。 \
Sourse中存放了源码（waring: 注释不多），分别是`Keil`与`STM32CubeIDE`工程文件，仅供参考，如有更好的实现方法欢迎交流。
