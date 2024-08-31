<h3 align="center">
    <img src="https://github.com/user-attachments/assets/ddc4a13d-de36-4802-9bd2-50c9376d580b" height="30" width="0px"/><br/>
    <img src="https://42seoul.kr/template/cms/seoul42/images/common/head_logo.png" width="250" alt="Logo"/><br/>
    <img src="https://github.com/user-attachments/assets/ddc4a13d-de36-4802-9bd2-50c9376d580b" height="70" width="0px"/>
    MiniRT Project for <a href="https://42seoul.kr/seoul42/main/view">42 Seoul</a><br/>
    <img src="https://github.com/user-attachments/assets/ddc4a13d-de36-4802-9bd2-50c9376d580b" height="10" width="0px"/>
</h3>

<p align="center">
This repository is for the 42 seoul project <strong>MiniRT</strong>.<br />The objective of this project is to render simple Computer-Generated-Images<br />and to implementing mathematical formulas.
</p>

<p align="center">
<img width="500" alt="image" src="https://github.com/user-attachments/assets/68a2acfb-d14d-477a-bff2-76631846d8a0">
</p>
<p align="center">
<img width="500" alt="image" src="https://github.com/user-attachments/assets/558550fb-1509-403b-8eb3-085d040c7e04">
</p>
<p align="center">
<img width="500" alt="image" src="https://github.com/user-attachments/assets/0df1b170-7ad5-4f68-bde6-117561806582">
</p>

## Features

- Support MacOS
- 4 simple geometric objects: plane, sphere, cylinder, cone
- Checkerboard color
- Bump map / custom image textures.
- Movement and change orientation
- Optimization with Multi-Threading

## Usage

- You can execute file with one argument [ConfigFile](https://github.com/minirtteam/minitRT#Config)

```bash
./miniRT <your config file name>
```
- Now you can see result with another window
- You can move four direction with keyboard `wasd`
- You can move updown with `mouse wheel`
- If you `click mouse wheel`, you can change your orientation
- `<ESC>` key for terminate program
- Put your custom config file in folder `test_file`. config file's extension must be '.rt'
- Put your texture image in folder `texture`

## Config
- You can set objects per one line
- Each line should follow this specific order
<details>
  <summary>see</summary>
  <ul>
    <li>
      Ambient lightning<br/>
      <code>A 0.2 255,255,255</code>
      <p>
        identifier: A<br />
        ambient lighting ratio in range [0.0,1.0]: 0.2<br />
        R,G,B colors in range [0-255]: 255, 255, 255
      </p>
    </li>
    <li>
      Camera<br/>
      <code>C -50.0,0,20 0,0,1 70</code>
      <p>
        identifier: C<br />
        x,y,z coordinates of the view point: -50.0,0,20<br />
        3d normalized orientation vector. In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0<br />
        FOV : Horizontal field of view in degrees in range [0,180]: 70
      </p>
    </li>
    <li>
      Lights<br/>
      <code>L -40.0,50.0,0.0 0.6 10,0,255</code>
      <p>
        identifier: L<br />
        x,y,z coordinates of the light point: -40.0,50.0,0.0<br />
        R,G,B colors in range [0-255]: 10, 0, 255
      </p>
    </li>
    <li>
      sphere<br/>
      <code>sp 0.0,0.0,20.6 12.6 10,0,255 [texture]</code>
      <p>
        identifier: sp<br />
        x,y,z coordinates of the sphere center: 0.0,0.0,20.6<br />
        the sphere diameter: 12.6<br />
        R,G,B colors in range [0-255]: 10, 0, 255<br />
        you can add '|' and another color behind R,G,B color setting to set checker board (optional)<br />
        you can add texture file name (optional)
      </p>
    </li>
    <li>
      cylinder<br/>
      <code>cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255 [texture]</code>
      <p>
        identifier: cy<br />
        x,y,z coordinates of the center of the cylinder: 50.0,0.0,20.6<br />
        3d normalized vector of axis of cylinder. In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0<br />
        the cylinder diameter: 14.2<br />
        the cylinder height: 21.42<br />
        R,G,B colors in range [0,255]: 10, 0, 255<br />
        you can add '|' and another color behind R,G,B color setting to set checker board (optional)<br />
        you can add texture file name (optional)
      </p>
    </li>
    <li>
      plane<br/>
      <code>pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225 [texture]</code>
      <p>
        identifier: pl<br />
        x,y,z coordinates of a point in the plane: 0.0,0.0,-10.0<br />
        3d normalized normal vector. In range [-1,1] for each x,y,z axis: 0.0,1.0,0.0<br />
        R,G,B colors in range [0-255]: 0,0,225<br />
        you can add '|' and another color behind R,G,B color setting to set checker board (optional)<br />
        you can add texture file name (optional)
      </p>
    </li>
    <li>
       cone<br/>
        <code>cn 0.0,0.0,-10.0 0.0,1.0,0.0 10 30 0,0,225 [texture]</code>
        <p>
        identifier: cn<br />
        x,y,z coordinates of a point in the plane: 0.0,0.0,-10.0<br />
        3d normalized normal vector. In range [-1,1] for each x,y,z axis: 0.0,1.0,0.0<br />
        height:10 <br />
        radius:30 <br />
        R,G,B colors in range [0-255]: 0,0,225<br />
        you can add '|' and another color behind R,G,B color setting to set checker board (optional)<br />
        you can add texture file name (optional)
      </p>
    </li>
  </ul>
</details>

### example file

```bash
A 1 200,200,200


L -5,20,20 0.7 50,120,150
L 5,20,20 0.7 50,120,150

C 0,2,20 0,0,-1 70




sp      0.0,1,-2 1.5 100,0,50

sp      0.2,1.3,-2 1.5 200,200,200
sp      -0.6,1.4,-1.4 0.1 0,0,0

sp      -0.2,1.3,-2 1.5 200,200,200
sp      0.6,1.4,-1.4 0.1 0,0,0

cy 0,1.3,-4 0,0,1 3 3 55,55,55
sp      0,2.3,-10 10 200,200,100 ./texture/earth_normal.xpm # Bumpmap texture

pl      0,-2,0 0,-1,0 0,140,0
pl      0,0,-20 0.8,0,0.6 200,50,200 ./texture/bricks_normal.xpm
pl      0,0,-20 -0.8,0,0.6 200,50,200 ./texture/bricks_normal.xpm



cn -7,0,-10 -0.6,-0.8,0 10 30 200,0,50
cn 7,0,-12 0.6,-0.8,0 10 30 200,0,50

cn -5,2,2 0,-0.6,0.8 2 4 200,200,50|80,80,80 # Two color of checker board
cy 5,2,2 0,-0.6,0.8 2 4 55,55,205|175,175,175
```
