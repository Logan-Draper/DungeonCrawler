#Compiler + flags
CXX = g++
CXXFLAGS = -Wall -g -w 

TARGET = PLAY

#Source files
SRCS = rest.cpp room_bank.cpp player.cpp AllnAll.cpp combat_sim.cpp combat_weight.cpp com_map.cpp enemy_stat_blocks.cpp fireball.cpp healing_item.cpp item_list.cpp level_up.cpp loot_gen.cpp movement.cpp room_gen.cpp spells.cpp thousand_arrow.cpp npc.cpp blessing.cpp
# Object files

OBJS = $(SRCS:.cpp=.o)

# Header files 
HEADERS = rest.h AllnAll.h combat_sim.h combat_weight.h com_map.h enemy_stat_blocks.h fireball.h healing_item.h itm_list.h level_up.h loot_gen.h movement.h npc.h room_gen.h spells.h thousand_arrow.h player.h blessing.h room_bank.h
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)
