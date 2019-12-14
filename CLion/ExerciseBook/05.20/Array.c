/*========
 * 多维数组
 =========*/

#include "Array.h"  //**▲05 数组和广义表**//

/*
 * 初始化。
 *
 * 初始化维数为dim的数组，可变参数指示各维度的大小。
 */
Status InitArray(Array* A, int dim, ...) {
    int elemtotal;  // 统计数组中总元素个数
    va_list ap;     // ap存放可变参数表信息，指示各维度的大小
    int i;
    
    if(A == NULL) {
        return ERROR;
    }
    
    if(dim < 1 || dim > MAX_ARRAY_DIM) {    // 数组维数有限制
        return ERROR;
    }
    
    (*A).dim = dim;     // 初始化数组维度
    
    // 初始化数组维度信息表
    (*A).bounds = (int*) malloc(dim * sizeof(int));
    if((*A).bounds == NULL) {
        exit(OVERFLOW);
    }
    
    // 若维度长度合法，则存入bounds，并求出A的元素总数elemtotal
    elemtotal = 1;
    
    // 使ap指向第一个可变参数，dim相当于起始标识
    va_start(ap, dim);
    
    for(i = 0; i < dim; i++) {
        // 记录当前维度的宽度
        (*A).bounds[i] = va_arg(ap, int);
        if((*A).bounds[i] <= 0) {
            return ERROR;
        }
        
        elemtotal *= A->bounds[i];
    }
    
    // 置空ap
    va_end(ap);
    
    // 初始化数组空间，以存放元素
    (*A).base = (ElemType*) malloc(elemtotal * sizeof(ElemType));
    if((*A).base == NULL) {
        exit(OVERFLOW);
    }
    
    // 初始化数组映像函数常量信息表
    (*A).constants = (int*) malloc(dim * sizeof(int));
    if((*A).constants == NULL) {
        exit(OVERFLOW);
    }
    
    // 遍历最后一个维度，每次总是需要跨越一个元素
    (*A).constants[dim - 1] = 1;
    for(i = dim - 2; i >= 0; i--) {
        (*A).constants[i] = (*A).bounds[i + 1] * (*A).constants[i + 1];
    }
    
    /*
     * 举例：
     * 对于三维数组[2,3,4]来说，bounds的值为<2,3,4>，constants的值为<12,4,1>
     * 分析bounds，第一维中包含2个元素，第二维中包含3个元素，第三维中包含4个元素
     * 分析constants，遍历第一维，每次需要跨过12个元素，遍历第二维，每次需要跨越4个元素，遍历第三维，每次需要跨越1个元素
     */
    
    return OK;
}

/*
 * 销毁(结构)。
 *
 * 销毁数组占用的空间。
 */
Status DestroyArray(Array* A) {
    if(A == NULL || (*A).base == NULL || (*A).bounds == NULL || (*A).constants == NULL) {
        return ERROR;
    }
    
    free((*A).base);
    (*A).base = NULL;
    
    free((*A).bounds);
    (*A).bounds = NULL;
    
    free((*A).constants);
    (*A).constants = NULL;
    
    (*A).dim = 0;
    
    return OK;
}

/*
 * 取值。
 *
 * 获取指定下标处的元素值，可变参数为dim个下标值，指示待获取元素所在下标。
 */
Status Value(Array A, ElemType* e, ...) {
    va_list ap;
    Status result;
    int off;
    
    va_start(ap, e);
    
    // 计算从起点元素到目标元素需要跨越的元素数量
    result = Locate(A, ap, &off);
    
    va_end(ap);
    
    if(result == OVERFLOW) {
        return result;
    }
    
    *e = *(A.base + off);
    
    return OK;
}

/*
 * 赋值。
 *
 * 为指定下标处的元素赋值，可变参数为dim个下标值，指示待赋值元素所在下标。
 */
Status Assign(Array* A, ElemType e, ...) {
    va_list ap;
    Status result;
    int off;
    
    va_start(ap, e);
    
    // 计算从起点元素到目标元素需要跨越的元素数量
    result = Locate(*A, ap, &off);
    
    va_end(ap);
    
    if(result == OVERFLOW) {
        return result;
    }
    
    *(A->base + off) = e;
    
    return OK;
}

/*
 * 求出ap指示的值在数组A中的相对位置，
 * 即计算从起点元素到目标元素需要跨越的元素数量。
 */
static Status Locate(Array A, va_list ap, int* off) {
    int i, ind;
    
    *off = 0;
    
    for(i = 0; i < A.dim; i++) {
        ind = va_arg(ap, int);
        
        // 保证下标不越界
        if(ind < 0 || ind >= A.bounds[i]) {
            return OVERFLOW;
        }
        
        // 某个维度的单位元素个数*需要跨过的单位
        *off += A.constants[i] * ind;
    }
    
    return OK;
}
