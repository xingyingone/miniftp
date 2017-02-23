#ifndef _HASH_H_
#define _HASH_H_

typedef struct hash hash_t;													//不想把结构暴露在外面
typedef unsigned int (*hashfunc_t)(unsigned int, void*);					//哈希函数（桶的个数 关键码）根据关键码得到桶的地址

hash_t* hash_alloc(unsigned int buckets, hashfunc_t hash_func);				//创建哈希表
void* hash_lookup_entry(hash_t *hash, void* key, unsigned int key_size);	//在哈希表中查找
void hash_add_entry(hash_t *hash, void *key, unsigned int key_size,			//往哈希表中添加一项
	void *value, unsigned int value_size);
void hash_free_entry(hash_t *hash, void *key, unsigned int key_size);		//从哈希表中删除一项


#endif /* _HASH_H_ */

