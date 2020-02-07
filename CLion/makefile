SRC_DIR :=
ifdef ROOT # 通过 make ROOT=xx 传递参数, 如果没有传递使用默认参数
	SRC_DIR = $(ROOT)
else
	SRC_DIR = CourseBook/0201_SqList
endif
ALL_SRC = $(wildcard $(SRC_DIR:%=%/*.c)) # 自动获取所有 .c 源文件
ALL_OBJ = $(ALL_SRC:%.c=%.o)  # 自动获取所有 .o 目标文件

# 静态库根目录
INCLUDE_STATIC = Status
# 静态库.c源码
ALL_LIB = $(wildcard $(INCLUDE_STATIC:%=%/*.c))
# 静态库.o任务名
ALL_LIB_O = $(ALL_LIB:%.c=%.o)

# 静态库目录
INCLUDE := -I./Status
# 静态库文件
LIBS    = $(ROOT_BUILD)/Status/static.a

# 编译根目录
ROOT_BUILD := build
# 编译源代码文件存放目录
BUILD_DIR := $(ROOT_BUILD)/$(SRC_DIR)
# 编译后静态库文件存放目录
INCLUDE_DIR = $(ROOT_BUILD)/Status

main: $(ALL_OBJ) $(LIBS) # 链接所有obj文件和静态链接库
	gcc $(INCLUDE) -g -Wall -o $(BUILD_DIR)/$@ $(addprefix $(ROOT_BUILD)/, $(ALL_OBJ)) $(LIBS) 
# main: $(ALL_OBJ) $(ALL_LIB_O)
# 	gcc $(INCLUDE) -Wall -o $(SRC_DIR)/$@ $(ALL_OBJ) $(ALL_LIB_O)

%.o: %.c # obj 目标文件生成依赖和命令
	gcc -g $(INCLUDE) -c -o $(ROOT_BUILD)/$@ $<

$(LIBS): $(ALL_LIB_O) # 静态库生成链接
	ar -rv $@ $(addprefix $(ROOT_BUILD)/, $^)

clean:	# 清理命令
	-rm -rf build

.PHONY: clean

# 自动更新头文件
sources = $(ALL_LIB) $(ALL_SRC)

include $(sources:.c=.d)

%.d: %.c pre
	set -e; rm -f $@; \
	$(CC) $(INCLUDE) -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $(ROOT_BUILD)/$@; \
	rm -f $@.$$$$

pre:
	mkdir -p $(INCLUDE_DIR); \
	mkdir -p $(BUILD_DIR);