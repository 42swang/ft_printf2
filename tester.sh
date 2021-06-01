#!/bin/bash

# 이거를 프로젝트 폴더로 수정하세요!
PROJ_PATH=.

# 실제 프로젝트 폴더 위치로 이동
REAL_PATH=$(cd $(dirname $0) && cd ${PROJ_PATH} && pwd)
echo 프로젝트 위치: $REAL_PATH


# 테스트 적용 위해 다시 컴파일 (make re 사용)
cd $REAL_PATH
make re
echo ""



# ########## 42TESTERS-PRINTF ##########
echo -e '######### 42TESTERS-PRINTF ##########'
git clone https://github.com/Mazoise/42TESTERS-PRINTF.git
cd 42TESTERS-PRINTF
bash runtest.sh
echo "#####42TESTS-PRINTF#####"
cd ..


SECONDS=0;
while sleep .5 && ((SECONDS <= 5)); do
    printf '\r%s: %2d' "Testing will start soon" "$((5-SECONDS))"
done
printf '\n'



# ########## PFT_2019 ##########
echo -e '#########PFT_2019##########'
git clone https://github.com/gavinfielder/pft.git pft_2019
cd pft_2019
make

./test
cat results.txt
cd ..

SECONDS=0;
while sleep .5 && ((SECONDS <= 5)); do
    printf '\r%s: %2d' "Testing will start soon" "$((5-SECONDS))"
done
printf '\n'

# ######### Test-42 #########
echo -e '######### Test-42 ##########'
git clone https://github.com/PandaCoustik/Test-42.git
cd Test-42/test_printf_classic
cp ../../libftprintf.a libftprintf.a
make
./ft_printf_tests
cd ../../

SECONDS=0;
while sleep .5 && ((SECONDS <= 5)); do
    printf '\r%s: %2d' "Testing will start soon" "$((5-SECONDS))"
done
printf '\n'

# ######### printf_lover_v2 #########
# (수동으로 동작 필요)
echo -e '######### printf_lover_v2 ##########'
git clone https://github.com/charMstr/printf_lover_v2.git
cd printf_lover_v2
./printf_lover.sh re
cd ..

SECONDS=0;
while sleep .5 && ((SECONDS <= 5)); do
    printf '\r%s: %2d' "Testing will start soon" "$((5-SECONDS))"
done
printf '\n'

# ###### 메모리 누수 테스트. 파일경로를 제대로 설정하시오 ######
echo -e '########## leaks test ##########'
make
gcc leaks.c libftprintf.a
./a.out
cat leaks.c
rm -rf a.out
