### memory order 
- relaxed 指令可以前后对调  

统计完成多少比交易，只要不出现1+1=1就行，结果和执行顺序无关
- consume & release 

后面有相关性 （data dependency or control dependency）的指令不能提前，前面的所有指令都不能延后
- aquire & release
比较常用
- acq_rel
- seq_cst

### 浏览器对象
- window
- document
- screen
- location
- localStorage
- history
- navigator
- self
- customElements
- visualViewport
- clientInformation
- styleMedia
- performance
- sessionStorage
- localStorage
- trustedTypes
- speechSynthesis

### LLVM BitCode

### H5 video

### Linux control group (cgroup)
cgroup主要用于控制进程组对某种资源的使用，这些资源包括但不限于：内存、CPU、外围设备、网络等。

例如，我们可以限制某一个进程组只能使用2GB的内存，如果超过就会发生OOM错误。

常用的资源控制子系统有

- CPU 子系统
- memory 子系统
- cpuset 子系统
- cpuacct 子系统
- blkio 子系统 
- devices 子系统
- freezer 子系统
- net_cls 子系统

### BFC
- BFC

根元素、float、abosute、fixed、overflow不为visible元素
BFC的主要处理浮动元素：
BFC包含浮动元素(即撑开父元素的高度)、margin不合并、BFC不会包围浮动元素
- IFC
inline 
- GFC
grid
- FFC
flex