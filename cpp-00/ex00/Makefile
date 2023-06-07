NAME = megaphone

SRCS = megaphone.cpp

CPP = c++

RM = rm -rf

FLAGS = --std=c++98 -Wall -Wextra -Werror

OBJS = $(SRCS:.cpp=.o)

%.o : %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

all		: $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)


clean :
	$(RM) $(OBJS)

fclean	:
	$(RM) $(OBJS)
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re