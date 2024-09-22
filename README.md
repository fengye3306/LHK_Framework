# LHK_Framework

*低耦合工作流方案*


## 开发环境  

|  项  |  开发环境  | 
|--------------|------------|
| ubuntu       | 22.04      |
| gcc          | 11.4.0     | 
| Cmake        | 3.22.1     | 
| OpenCV       | 4.8.1      | 
| Qt           | 5.15.2     |


项目预设为windows，ubuntu双平台，因为个人在ubuntu环境进行开发，且处于开发早期，所以并未做双平台适配。   


## 构建

1. 安装cmake-gui(cmake version >= 3.10)
1. 安装gcc编译器，(至少支持c++17标准)
2. 构建Qt5（qt version >= 5.15.2） 
3. 构建OpenCV4 (项目环境为OpenCV4.8.1)  
4. 构建主工程，Cmake有几个值开关需要注意配置，通过`-D`,或于camke构建工具中进行修改      

|  开关              |  含义  | 
|-------------------|------------|
| USE_QT6           | 是否使用qt6（off为否， on为开）     |
| BUILD_TESTING     | 构建测试   （off为否， on为开）     | 
| BUILD_EXAMPLES    | 构建历程   （off为否， on为开）     | 



## 架构思路  


