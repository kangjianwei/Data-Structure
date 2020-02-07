SRC_DIR :=
ifdef ROOT # 通过 make ROOT=xx 传递参数
	SRC_DIR = $(ROOT)
else
	SRC_DIR = CourseBook/0201_SqList
endif
ALL_SRC = $(wildcard $(SRC_DIR:%=%/*.c)) # 自动获取所有 .c 源文件
ROOT_BUILD := build
BUILD_DIR := $(ROOT_BUILD)/$(SRC_DIR)
ALL_OBJ = $(ALL_SRC:%.c=%.o)  # 自动获取所有 .o 目标文件
ALL_DEP = $(ALL_SRC:%.c=%.d) # 得到一系列 .d 依赖文件列表

INCLUDE := -I./Status
LIBS    := $(ROOT_BUILD)/Status/static.a

INCLUDE_DIR = $(ROOT_BUILD)/Status
INCLUDE_STATIC = Status
ALL_LIB = $(wildcard $(INCLUDE_STATIC:%=%/*.c))
ALL_LIB_O = $(ALL_LIB:%.c=%.o)

main: $(ALL_OBJ) $(LIBS) # 链接所有obj文件和静态链接库
	mkdir -p $(BUILD_DIR); \
	gcc $(INCLUDE) -g -Wall -o $(BUILD_DIR)/$@ $(addprefix $(ROOT_BUILD)/, $(ALL_OBJ)) $(LIBS) 
# main: $(ALL_OBJ) $(ALL_LIB_O)
# 	gcc $(INCLUDE) -Wall -o $(SRC_DIR)/$@ $(ALL_OBJ) $(ALL_LIB_O)

%.o: %.c # obj 目标文件生成依赖和命令
	mkdir -p $(BUILD_DIR); \
	gcc -g $(INCLUDE) -c -o $(ROOT_BUILD)/$@ $<

$(LIBS): $(ALL_LIB_O) # 静态库生成链接
	ar -rv $@ $(addprefix $(ROOT_BUILD)/, $^)

clean:	# 清理命令
	-rm -rf build

.PHONY: clean

# 自动更新头文件
sources = $(ALL_LIB) $(ALL_SRC)

include $(sources:.c=.d)

%.d: %.c
	set -e; rm -f $@; \
	$(CC) $(INCLUDE) -MM $(CPPFLAGS) $< > $@.$$$$; \
	mkdir -p $(INCLUDE_DIR); \
	mkdir -p $(BUILD_DIR); \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $(ROOT_BUILD)/$@; \
	rm -f $@.$$$$