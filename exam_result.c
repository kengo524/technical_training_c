#include <stdio.h>
int main(void){

	int math_physics_result[5][2]={ 
						{72, 48 } ,
						{88, 39 } ,
						{72, 91 } ,
						{81, 82 } ,
						{68, 78 }  };

	//生徒のテスト点数一覧。                     
	for(int i = 0; i < 5; i++) {
			for(int j = 0; j < 2; j++) {
				if(j < 1) {
					printf("[数学：%d点,", math_physics_result[i][j]);
				} else {
					printf("物理：%d点]\n", math_physics_result[i][j]);
				}
			}
	}

	//数学の合計点、最高点、最低点数を格納する変数。
	int sum_math_score = 0;
	int math_max_score= 0;
	int math_min_score = 100;

	//物理の合計点、最高点、最低点数を格納する変数。
	int sum_physics_score = 0;
	int physics_max_score = 0;
	int physics_min_score = 100;

	//数学＋物理の最も高い合計点を格納する変数。
	int best_score = 0;

	for(int i = 0; i < 5; i++) {
		sum_math_score += math_physics_result[i][0];
		sum_physics_score += math_physics_result[i][1];

		if( best_score < (math_physics_result[i][0] + math_physics_result[i][1]) ){
			best_score = (math_physics_result[i][0] + math_physics_result[i][1]);
		}

		for(int j = 0; j < 2; j++) {
			if(j == 0) {
				if(math_physics_result[i][j] > math_max_score){
					math_max_score = math_physics_result[i][j];
				}
				if(math_physics_result[i][j] < math_min_score){
					math_min_score = math_physics_result[i][j];
				}
			}
			if(j == 1){
				if(math_physics_result[i][j] > physics_max_score){
					physics_max_score = math_physics_result[i][j];
				}
			}
			if(math_physics_result[i][j] < physics_min_score){
				physics_min_score = math_physics_result[i][j];
			}
		}
	};
    
	//数学の点数を表示
	printf("数学の最高点は、%d点\n",math_max_score);
	printf("数学の最低点は、%d点\n",math_min_score);
	printf("数学の平均点は、%.1f点\n",(float)sum_math_score/5);
　　//物理の点数を表示
	printf("物理の最高点は、%d点\n",physics_max_score);
	printf("物理の最低点は、%d点\n",physics_min_score);
	printf("物理の平均点は、%.1f点\n",(float)sum_physics_score/5);
　　//数学と物理の合計点数を表示
    printf("数学と物理の合計点が最も高い生徒の点数は、%d点\n",best_score);
}
