# 村人取引（キ）ー

## なにこれ

ProMicroを使ってMinecraftの村人との取引をラクにするキーを作るプログラムです。マウスカーソルで何度も移動とクリックをしなければならない取引も、取引枠にカーソルを合わせてからキーを1つ押しっぱなしにするだけで簡単に取引できるようになります。

![動作の様子](https://github.com/Akkiesoft/mc-villager-trading-key/blob/image/demo.gif)

(Youtube: https://www.youtube.com/watch?v=qutj83jxQXI )

## 使い方

設定部分は、key配列、x配列、y配列の3つです。key配列は4-packキーボード( http://www.40percent.club/2017/07/4-pack.html )に最適化されていますが、他のProMicroを使った似たような構造のキーボードにも応用できるでしょう。x配列、y配列はkey配列のキースイッチ番号に対応した各キーのマウスカーソル移動量を記述します。

![1キーあたりの設定](https://github.com/Akkiesoft/mc-villager-trading-key/blob/image/array.jpg)

カーソルのX,Yの移動量は、DPIなどの設定やRetinaモード(Mac)などによって、単純にスクリーンショットを取得してピクセル数を計測するだけでは思ったとおりに移動しないことのほうが多くなっています。何度か適当な値を入れて調整していくと良いでしょう。

![移動量の設定](https://github.com/Akkiesoft/mc-villager-trading-key/blob/image/measure.jpg)

# License

The MIT License (MIT)

Copyright (c) 2020 Akira Ouchi <akkiesoft -at- marokun.net> a.k.a. [@Akkiesoft](https://social.mikutter.hachune.net/@akkiesoft)
