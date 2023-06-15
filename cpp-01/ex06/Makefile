NAME = Harl

SRCS = main.cpp Harl.cpp

CXX = c++

RM = rm -rf

FLAGS = --std=c++98 -Wall -Wextra -Werror

OBJS = $(SRCS:.cpp=.o)

%.o : %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

all		: $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -o $(NAME)


clean :
	$(RM) $(OBJS)

fclean	:
	$(RM) $(OBJS)
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re