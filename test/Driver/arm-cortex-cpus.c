// ================== Check default CPU on each major architecture
// RUN: %clang -target arm -mcpu=generic -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-GENERIC %s
// CHECK-GENERIC: "-cc1"{{.*}} "-triple" "armv4t-{{.*}} "-target-cpu" "generic"

// RUN: %clang -target armeb -mcpu=generic -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-GENERIC %s
// CHECK-BE-GENERIC: "-cc1"{{.*}} "-triple" "armebv4t-{{.*}} "-target-cpu" "generic"

// RUN: %clang -target arm -mthumb -mcpu=generic -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-GENERIC-THUMB %s
// CHECK-GENERIC-THUMB: "-cc1"{{.*}} "-triple" "thumbv4t-{{.*}} "-target-cpu" "generic"

// RUN: %clang -target armeb -mthumb -mcpu=generic -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-GENERIC-THUMB %s
// CHECK-BE-GENERIC-THUMB: "-cc1"{{.*}} "-triple" "thumbebv4t-{{.*}} "-target-cpu" "generic"

// RUN: %clang -target armv4t -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V4T %s
// RUN: %clang -target arm -march=armv4t -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V4T %s
// CHECK-V4T: "-cc1"{{.*}} "-triple" "armv4t-{{.*}} "-target-cpu" "arm7tdmi"

// RUN: %clang -target armv4t -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V4T-THUMB %s
// RUN: %clang -target arm -mthumb -march=armv4t -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V4T-THUMB %s
// CHECK-V4T-THUMB: "-cc1"{{.*}} "-triple" "thumbv4t-{{.*}} "-target-cpu" "arm7tdmi"

// RUN: %clang -target armv5 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V5 %s
// RUN: %clang -target arm -march=armv5 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V5 %s
// RUN: %clang -target armv5t -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V5 %s
// RUN: %clang -target arm -march=armv5t -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V5 %s
// CHECK-V5: "-cc1"{{.*}} "-triple" "armv5-{{.*}} "-target-cpu" "arm10tdmi"

// RUN: %clang -target armv5 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V5-THUMB %s
// RUN: %clang -target arm -march=armv5 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V5-THUMB %s
// RUN: %clang -target armv5t -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V5-THUMB %s
// RUN: %clang -target arm -march=armv5 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V5-THUMB %s
// CHECK-V5-THUMB: "-cc1"{{.*}} "-triple" "thumbv5-{{.*}} "-target-cpu" "arm10tdmi"

// RUN: %clang -target armv5e -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V5E %s
// RUN: %clang -target arm -march=armv5e -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V5E %s
// CHECK-V5E: "-cc1"{{.*}} "-triple" "armv5e-{{.*}} "-target-cpu" "arm1022e"

// RUN: %clang -target armv5e -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V5E-THUMB %s
// RUN: %clang -target arm -march=armv5e -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V5E-THUMB %s
// CHECK-V5E-THUMB: "-cc1"{{.*}} "-triple" "thumbv5e-{{.*}} "-target-cpu" "arm1022e"

// FIXME %clang -target armv5tej -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V5TEJ %s
// RUN: %clang -target arm -march=armv5tej -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V5TEJ %s
// CHECK-V5TEJ: "-cc1"{{.*}} "-triple" "armv5e-{{.*}} "-target-cpu" "arm926ej-s"

// FIXME %clang -target armv5tej -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V5TEJ-THUMB %s
// RUN: %clang -target arm -march=armv5tej -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V5TEJ-THUMB %s
// CHECK-V5TEJ-THUMB: "-cc1"{{.*}} "-triple" "thumbv5e-{{.*}} "-target-cpu" "arm926ej-s"

// RUN: %clang -target armv6 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6 %s
// RUN: %clang -target arm -march=armv6 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6 %s
// CHECK-V6: "-cc1"{{.*}} "-triple" "armv6-{{.*}} "-target-cpu" "arm1136jf-s"

// RUN: %clang -target armv6 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6-THUMB %s
// RUN: %clang -target arm -march=armv6 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6-THUMB %s
// CHECK-V6-THUMB: "-cc1"{{.*}} "-triple" "thumbv6-{{.*}} "-target-cpu" "arm1136jf-s"

// FIXME %clang -target armv6j -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6J %s
// RUN: %clang -target arm -march=armv6j -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6J %s
// CHECK-V6J: "-cc1"{{.*}} "-triple" "armv6-{{.*}} "-target-cpu" "arm1136j-s"

// FIXME %clang -target armv6j -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6J-THUMB %s
// RUN: %clang -target arm -march=armv6j -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6J-THUMB %s
// CHECK-V6J-THUMB: "-cc1"{{.*}} "-triple" "thumbv6-{{.*}} "-target-cpu" "arm1136j-s"

// FIXME %clang -target armv6z -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6Z %s
// FIXME %clang -target arm -march=armv6z -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6Z %s
// CHECK-V6Z: "-cc1"{{.*}} "-triple" "armv6-{{.*}} "-target-cpu" "arm1176jzf-s"

// FIXME %clang -target armv6z -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6Z-THUMB %s
// FIXME %clang -target arm -march=armv6z -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6Z-THUMB %s
// CHECK-V6Z-THUMB: "-cc1"{{.*}} "-triple" "thumbv6-{{.*}} "-target-cpu" "arm1176jzf-s"

// RUN: %clang -target armv6k -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6K %s
// RUN: %clang -target arm -march=armv6k -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6K %s
// CHECK-V6K: "-cc1"{{.*}} "-triple" "armv6k-{{.*}} "-target-cpu" "arm1176jzf-s"

// RUN: %clang -target armv6k -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6K-THUMB %s
// RUN: %clang -target arm -march=armv6k -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6K-THUMB %s
// CHECK-V6K-THUMB: "-cc1"{{.*}} "-triple" "thumbv6k-{{.*}} "-target-cpu" "arm1176jzf-s"

// RUN: %clang -target armv6t2 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6T2 %s
// RUN: %clang -target arm -march=armv6t2 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6T2 %s
// CHECK-V6T2: "-cc1"{{.*}} "-triple" "armv6t2-{{.*}} "-target-cpu" "arm1156t2-s"

// RUN: %clang -target armv6t2 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6T2-THUMB %s
// RUN: %clang -target arm -march=armv6t2 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6T2-THUMB %s
// CHECK-V6T2-THUMB: "-cc1"{{.*}} "-triple" "thumbv6t2-{{.*}} "-target-cpu" "arm1156t2-s"

// RUN: %clang -target armv6m -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6M %s
// RUN: %clang -target arm -march=armv6m -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6M %s
// RUN: %clang -target armv6sm -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6M %s
// RUN: %clang -target arm -march=armv6sm -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6M %s
// CHECK-V6M: "-cc1"{{.*}} "-triple" "thumbv6m-{{.*}} "-target-cpu" "cortex-m0"

// RUN: %clang -target armv6m -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6M-BIG %s
// RUN: %clang -target arm -march=armv6m -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6M-BIG %s
// CHECK-V6M-BIG: "-cc1"{{.*}} "-triple" "thumbebv6m-{{.*}} "-target-cpu" "cortex-m0"

// RUN: %clang -target armv7m -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7M %s
// RUN: %clang -target arm -march=armv7-m -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7M %s
// CHECK-V7M: "-cc1"{{.*}} "-triple" "thumbv7m-{{.*}} "-target-cpu" "cortex-m3"

// RUN: %clang -target armv7em -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7EM %s
// RUN: %clang -target arm -march=armv7e-m -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7EM %s
// CHECK-V7EM: "-cc1"{{.*}} "-triple" "thumbv7em-{{.*}} "-target-cpu" "cortex-m4"

// RUN: %clang -target armv7em -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7EM-BIG %s
// RUN: %clang -target arm -march=armv7e-m -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7EM-BIG %s
// CHECK-V7EM-BIG: "-cc1"{{.*}} "-triple" "thumbebv7em-{{.*}} "-target-cpu" "cortex-m4"

// RUN: %clang -target armv6m-apple-darwin -arch armv6m -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6M-DARWIN %s
// CHECK-V6M-DARWIN: "-cc1"{{.*}} "-triple" "thumbv6m-{{.*}} "-target-cpu" "cortex-m0"

// RUN: %clang -target armv7m-apple-darwin -arch armv7m -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7M-DARWIN %s
// CHECK-V7M-DARWIN: "-cc1"{{.*}} "-triple" "thumbv7m-{{.*}} "-target-cpu" "cortex-m3"

// RUN: %clang -target armv7em-apple-darwin -arch armv7em -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7EM-DARWIN %s
// CHECK-V7EM-DARWIN: "-cc1"{{.*}} "-triple" "thumbv7em-{{.*}} "-target-cpu" "cortex-m4"

// RUN: %clang -target armv7a-linux-gnueabi -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7A %s
// RUN: %clang -target arm-linux-gnueabi -march=armv7-a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7A %s
// CHECK-V7A: "-cc1"{{.*}} "-triple" "armv7-{{.*}} "-target-cpu" "cortex-a8"

// RUN: %clang -target armv7a-linux-gnueabi -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7A-THUMB %s
// RUN: %clang -target arm-linux-gnueabi -march=armv7-a -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7A-THUMB %s
// CHECK-V7A-THUMB: "-cc1"{{.*}} "-triple" "thumbv7-{{.*}} "-target-cpu" "cortex-a8"

// RUN: %clang -target armv7r-linux-gnueabi -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7R %s
// RUN: %clang -target arm-linux-gnueabi -march=armv7-r -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7R %s
// CHECK-V7R: "-cc1"{{.*}} "-triple" "armv7r-{{.*}} "-target-cpu" "cortex-r4"

// RUN: %clang -target armv7r-linux-gnueabi -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7R-THUMB %s
// RUN: %clang -target arm-linux-gnueabi -march=armv7-r -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7R-THUMB %s
// CHECK-V7R-THUMB: "-cc1"{{.*}} "-triple" "thumbv7r-{{.*}} "-target-cpu" "cortex-r4"

// RUN: %clang -target armv8 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A %s
// RUN: %clang -target arm -march=armv8 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A %s
// RUN: %clang -target armv8a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A %s
// RUN: %clang -target arm -march=armv8a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A %s
// RUN: %clang -target arm -march=armv8-a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A %s
// RUN: %clang -target armv8 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A %s
// RUN: %clang -target arm -march=armv8 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A %s
// RUN: %clang -target armv8a -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A %s
// RUN: %clang -target arm -march=armv8a -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A %s
// RUN: %clang -target arm -mlittle-endian -march=armv8-a -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A %s
// CHECK-V8A: "-cc1"{{.*}} "-triple" "armv8-{{.*}}" "-target-cpu" "cortex-a53"

// RUN: %clang -mcpu=generic -target armv8 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-GENERIC %s
// RUN: %clang -mcpu=generic -target arm -march=armv8 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-GENERIC %s
// RUN: %clang -mcpu=generic -target armv8a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-GENERIC %s
// RUN: %clang -mcpu=generic -target arm -march=armv8a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-GENERIC %s
// RUN: %clang -mcpu=generic -target arm -march=armv8-a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-GENERIC %s
// RUN: %clang -mcpu=generic -target armv8 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-GENERIC %s
// RUN: %clang -mcpu=generic -target arm -march=armv8 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-GENERIC %s
// RUN: %clang -mcpu=generic -target armv8a -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-GENERIC %s
// RUN: %clang -mcpu=generic -target arm -march=armv8a -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-GENERIC %s
// RUN: %clang -mcpu=generic -target arm -mlittle-endian -march=armv8-a -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-GENERIC %s
// CHECK-V8A-GENERIC: "-cc1"{{.*}} "-triple" "armv8-{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target armebv8 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A %s
// RUN: %clang -target armeb -march=armebv8 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A %s
// RUN: %clang -target armebv8a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A %s
// RUN: %clang -target armeb -march=armebv8a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A %s
// RUN: %clang -target armeb -march=armebv8-a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A %s
// RUN: %clang -target armv8 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A %s
// RUN: %clang -target arm -march=armebv8 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A %s
// RUN: %clang -target armv8a -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A %s
// RUN: %clang -target arm -march=armebv8a -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A %s
// RUN: %clang -target arm -march=armebv8-a -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A %s
// CHECK-BE-V8A: "-cc1"{{.*}} "-triple" "armebv8-{{.*}}" "-target-cpu" "cortex-a53"

// RUN: %clang -target armv8 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-THUMB %s
// RUN: %clang -target arm -march=armv8 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-THUMB %s
// RUN: %clang -target armv8a -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-THUMB %s
// RUN: %clang -target arm -march=armv8a -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-THUMB %s
// RUN: %clang -target armv8 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-THUMB %s
// RUN: %clang -target arm -march=armv8 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-THUMB %s
// RUN: %clang -target armv8a -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-THUMB %s
// RUN: %clang -target arm -march=armv8a -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-THUMB %s
// CHECK-V8A-THUMB: "-cc1"{{.*}} "-triple" "thumbv8-{{.*}}" "-target-cpu" "cortex-a53"

// RUN: %clang -target armebv8 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A-THUMB %s
// RUN: %clang -target armeb -march=armebv8 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A-THUMB %s
// RUN: %clang -target armebv8a -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A-THUMB %s
// RUN: %clang -target armeb -march=armebv8a -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A-THUMB %s
// RUN: %clang -target armv8 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A-THUMB %s
// RUN: %clang -target arm -march=armebv8 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A-THUMB %s
// RUN: %clang -target armv8a -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A-THUMB %s
// RUN: %clang -target arm -march=armebv8a -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A-THUMB %s
// CHECK-BE-V8A-THUMB: "-cc1"{{.*}} "-triple" "thumbebv8-{{.*}}" "-target-cpu" "cortex-a53"

// RUN: %clang -target arm -march=armv8.1a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A %s
// RUN: %clang -target armv8.1a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A %s
// RUN: %clang -target arm -march=armv8.1-a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A %s
// RUN: %clang -target arm -march=armv8.1a -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A %s
// RUN: %clang -target armv8.1a -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A %s
// RUN: %clang -target arm -march=armv8.1a -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A %s
// RUN: %clang -target arm -mlittle-endian -march=armv8.1-a -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A %s
// RUN: %clang -mcpu=generic -target arm -march=armv8.1a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A %s
// RUN: %clang -mcpu=generic -target armv8.1a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A %s
// RUN: %clang -mcpu=generic -target arm -march=armv8.1-a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A %s
// RUN: %clang -mcpu=generic -target arm -march=armv8.1a -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A %s
// RUN: %clang -mcpu=generic -target armv8.1a -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A %s
// RUN: %clang -mcpu=generic -target arm -march=armv8.1a -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A %s
// RUN: %clang -mcpu=generic -target arm -mlittle-endian -march=armv8.1-a -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A %s
// CHECK-V81A: "-cc1"{{.*}} "-triple" "armv8.1a-{{.*}}" "-target-cpu" "generic" "-target-feature" "+v8.1a"

// RUN: %clang -target armebv8.1a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V81A %s
// RUN: %clang -target armeb -march=armebv8.1a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V81A %s
// RUN: %clang -target armeb -march=armebv8.1-a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V81A %s
// RUN: %clang -target armv8.1a -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V81A %s
// RUN: %clang -target arm -march=armebv8.1a -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V81A %s
// RUN: %clang -target arm -march=armebv8.1-a -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V81A %s
// CHECK-BE-V81A: "-cc1"{{.*}} "-triple" "armebv8.1a-{{.*}}" "-target-cpu" "generic" "-target-feature" "+v8.1a"

// RUN: %clang -target armv8.1a -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A-THUMB %s
// RUN: %clang -target arm -march=armv8.1a -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A-THUMB %s
// RUN: %clang -target arm -march=armv8.1-a -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A-THUMB %s
// RUN: %clang -target armv8.1a -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A-THUMB %s
// RUN: %clang -target arm -march=armv8.1a -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A-THUMB %s
// RUN: %clang -target arm -march=armv8.1-a -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A-THUMB %s
// CHECK-V81A-THUMB: "-cc1"{{.*}} "-triple" "thumbv8.1a-{{.*}}" "-target-cpu" "generic" "-target-feature" "+v8.1a"

// RUN: %clang -target armebv8.1a -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V81A-THUMB %s
// RUN: %clang -target armeb -march=armebv8.1a -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V81A-THUMB %s
// RUN: %clang -target armeb -march=armebv8.1-a -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V81A-THUMB %s
// RUN: %clang -target armv8.1a -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V81A-THUMB %s
// RUN: %clang -target arm -march=armebv8.1a -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V81A-THUMB %s
// RUN: %clang -target arm -march=armebv8.1-a -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V81A-THUMB %s
// CHECK-BE-V81A-THUMB: "-cc1"{{.*}} "-triple" "thumbebv8.1a-{{.*}}" "-target-cpu" "generic" "-target-feature" "+v8.1a"

// ================== Check that a bogus architecture gives an error
// RUN: %clang -target arm -march=armbogusv6 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BOGUS %s
// CHECK-BOGUS: error: {{.*}} does not support '-march=armbogusv6' 
// RUN: %clang -target arm---eabihf -march=armbogusv7 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BOGUS-HF %s
// CHECK-BOGUS-HF: error: {{.*}} does not support '-march=armbogusv7' 
// RUN: %clang -target arm -march=armv6bogus -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BOGUS2 %s
// CHECK-BOGUS2: error: {{.*}} does not support '-march=armv6bogus'
// RUN: %clang -target arm -march=bogus -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BOGUS3 %s
// CHECK-BOGUS3: error: {{.*}} does not support '-march=bogus'

// ================== Check that a bogus CPU gives an error
// RUN: %clang -target arm -mcpu=bogus -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BOGUS-CPU %s
// CHECK-BOGUS-CPU: error: {{.*}} does not support '-mcpu=bogus'

// ================== Check default Architecture on each ARM11 CPU
// RUN: %clang -target arm-linux-gnueabi -mcpu=arm1136j-s -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV6 %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=arm1136jf-s -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV6 %s
// CHECK-CPUV6: "-cc1"{{.*}} "-triple" "armv6-{{.*}}

// RUN: %clang -target arm-linux-gnueabi -mcpu=arm1176jz-s -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV6K %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=arm1176jzf-s -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV6K %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=mpcore -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV6K %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=mpcorenovfp -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV6K %s
// CHECK-CPUV6K: "-cc1"{{.*}} "-triple" "armv6k-{{.*}}

// RUN: %clang -target arm-linux-gnueabi -mcpu=arm1156t2-s -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV6T2 %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=arm1156t2f-s -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV6T2 %s
// CHECK-CPUV6T2: "-cc1"{{.*}} "-triple" "armv6t2-{{.*}}

// ================== Check default Architecture on each Cortex CPU
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a5 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a7 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a8 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a9 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a12 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a15 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a17 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a5 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a7 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a8 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a9 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a12 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a15 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a17 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A %s
// CHECK-CPUV7A: "-cc1"{{.*}} "-triple" "armv7-{{.*}}

// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-a5 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A %s
// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-a7 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A %s
// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-a8 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A %s
// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-a9 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A %s
// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-a12 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A %s
// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-a15 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A %s
// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-a17 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a5 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a7 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a8 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a9 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a12 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a15 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a17 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A %s
// CHECK-BE-CPUV7A: "-cc1"{{.*}} "-triple" "armebv7-{{.*}}

// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a5 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A-THUMB %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a7 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A-THUMB %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a8 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A-THUMB %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a9 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A-THUMB %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a12 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A-THUMB %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a15 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A-THUMB %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a17 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A-THUMB %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a5 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A-THUMB %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a7 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A-THUMB %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a8 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A-THUMB %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a9 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A-THUMB %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a12 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A-THUMB %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a15 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A-THUMB %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a17 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A-THUMB %s
// CHECK-CPUV7A-THUMB: "-cc1"{{.*}} "-triple" "thumbv7-{{.*}}

// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-a5 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A-THUMB %s
// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-a7 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A-THUMB %s
// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-a8 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A-THUMB %s
// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-a9 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A-THUMB %s
// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-a12 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A-THUMB %s
// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-a15 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A-THUMB %s
// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-a17 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A-THUMB %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a5 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A-THUMB %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a7 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A-THUMB %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a8 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A-THUMB %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a9 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A-THUMB %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a12 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A-THUMB %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a15 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A-THUMB %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a17 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A-THUMB %s
// CHECK-BE-CPUV7A-THUMB: "-cc1"{{.*}} "-triple" "thumbebv7-{{.*}}

// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-m0 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV6M %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-m0plus -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV6M %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-m1 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV6M %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=sc000 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV6M %s
// CHECK-CPUV6M: "-cc1"{{.*}} "-triple" "thumbv6m-{{.*}}

// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-m3 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7M %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-m3 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7M %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=sc300 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7M %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=sc300 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7M %s
// CHECK-CPUV7M: "-cc1"{{.*}} "-triple" "thumbv7m-{{.*}}

// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-m3 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7M %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-m3 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7M %s
// CHECK-BE-CPUV7M: "-cc1"{{.*}} "-triple" "thumbebv7m-{{.*}}

// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-m4 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7EM %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-m7 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7EM %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-m4 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7EM %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-m7 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7EM %s
// CHECK-CPUV7EM: "-cc1"{{.*}} "-triple" "thumbv7em-{{.*}}

// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-m4 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7EM %s
// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-m7 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7EM %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-m4 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7EM %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-m7 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7EM %s
// CHECK-BE-CPUV7EM: "-cc1"{{.*}} "-triple" "thumbebv7em-{{.*}}

// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r4 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r4f -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r5 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r7 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r4 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r4f -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r5 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r7 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R %s
// CHECK-CPUV7R: "-cc1"{{.*}} "-triple" "armv7r-{{.*}}

// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-r4 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R %s
// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-r4f -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R %s
// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-r5 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R %s
// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-r7 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r4 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r4f -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r5 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r7 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R %s
// CHECK-BE-CPUV7R: "-cc1"{{.*}} "-triple" "armebv7r-{{.*}}

// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r4 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R-THUMB %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r4f -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R-THUMB %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r5 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R-THUMB %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r7 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R-THUMB %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r4 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R-THUMB %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r4f -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R-THUMB %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r5 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R-THUMB %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r7 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R-THUMB %s
// CHECK-CPUV7R-THUMB: "-cc1"{{.*}} "-triple" "thumbv7r-{{.*}}

// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-r4 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R-THUMB %s
// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-r4f -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R-THUMB %s
// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-r5 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R-THUMB %s
// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-r7 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R-THUMB %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r4 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R-THUMB %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r4f -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R-THUMB %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r5 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R-THUMB %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r7 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R-THUMB %s
// CHECK-BE-CPUV7R-THUMB: "-cc1"{{.*}} "-triple" "thumbebv7r-{{.*}}

// RUN: %clang -target arm -mcpu=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A %s
// RUN: %clang -target arm -mcpu=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A %s
// RUN: %clang -target arm -mcpu=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A %s
// RUN: %clang -target arm -mcpu=cortex-a53 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A %s
// RUN: %clang -target arm -mcpu=cortex-a57 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A %s
// RUN: %clang -target arm -mcpu=cortex-a72 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A %s
// CHECK-CPUV8A: "-cc1"{{.*}} "-triple" "armv8-{{.*}}

// RUN: %clang -target armeb -mcpu=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A %s
// RUN: %clang -target armeb -mcpu=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A %s
// RUN: %clang -target armeb -mcpu=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A %s
// RUN: %clang -target arm -mcpu=cortex-a53 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A %s
// RUN: %clang -target arm -mcpu=cortex-a57 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A %s
// RUN: %clang -target arm -mcpu=cortex-a72 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A %s
// CHECK-BE-CPUV8A: "-cc1"{{.*}} "-triple" "armebv8-{{.*}}

// RUN: %clang -target arm -mcpu=cortex-a53 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A-THUMB %s
// RUN: %clang -target arm -mcpu=cortex-a57 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A-THUMB %s
// RUN: %clang -target arm -mcpu=cortex-a72 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A-THUMB %s
// RUN: %clang -target arm -mcpu=cortex-a53 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A-THUMB %s
// RUN: %clang -target arm -mcpu=cortex-a57 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A-THUMB %s
// RUN: %clang -target arm -mcpu=cortex-a72 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A-THUMB %s
// CHECK-CPUV8A-THUMB: "-cc1"{{.*}} "-triple" "thumbv8-{{.*}}

// RUN: %clang -target armeb -mcpu=cortex-a53 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A-THUMB %s
// RUN: %clang -target armeb -mcpu=cortex-a57 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A-THUMB %s
// RUN: %clang -target armeb -mcpu=cortex-a72 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A-THUMB %s
// RUN: %clang -target arm -mcpu=cortex-a53 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A-THUMB %s
// RUN: %clang -target arm -mcpu=cortex-a57 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A-THUMB %s
// RUN: %clang -target arm -mcpu=cortex-a72 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A-THUMB %s
// CHECK-BE-CPUV8A-THUMB: "-cc1"{{.*}} "-triple" "thumbebv8-{{.*}}

// ================== Check whether -mcpu accepts mixed-case values.
// RUN: %clang -target arm-linux-gnueabi -mcpu=Cortex-a5 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CASE-INSENSITIVE-CPUV7A %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-A7 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CASE-INSENSITIVE-CPUV7A %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=CORTEX-a8 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CASE-INSENSITIVE-CPUV7A %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=Cortex-A9 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CASE-INSENSITIVE-CPUV7A %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=corteX-A12 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CASE-INSENSITIVE-CPUV7A %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=CorteX-a15 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CASE-INSENSITIVE-CPUV7A %s
// RUN: %clang -target arm-linux-gnueabi -mcpu=CorteX-A17 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CASE-INSENSITIVE-CPUV7A %s
// CHECK-CASE-INSENSITIVE-CPUV7A: "-cc1"{{.*}} "-triple" "armv7-{{.*}}

// ================== Check whether -march accepts mixed-case values.
// RUN: %clang -target arm -march=Armv5 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CASE-INSENSITIVE-V5 %s
// RUN: %clang -target arm -march=ARMV5 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CASE-INSENSITIVE-V5 %s
// CHECK-CASE-INSENSITIVE-V5: "-cc1"{{.*}} "-triple" "armv5-{{.*}} "-target-cpu" "arm10tdmi"

// RUN: %clang -target arm -march=Armv6t2 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CASE-INSENSITIVE-V6T2-THUMB %s
// RUN: %clang -target arm -march=ARMV6T2 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CASE-INSENSITIVE-V6T2-THUMB %s
// CHECK-CASE-INSENSITIVE-V6T2-THUMB: "-cc1"{{.*}} "-triple" "thumbv6t2-{{.*}} "-target-cpu" "arm1156t2-s"
