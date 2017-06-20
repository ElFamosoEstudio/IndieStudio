//
// CountDown.hpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Sat Jun 17 07:22:26 2017 akram abd-ali
// Last update Tue Jun 20 20:35:35 2017 akram abd-ali
//

#ifndef	        COUNT_DOWN_HPP
# define	COUNT_DOWN_HPP

# include <chrono>

namespace	indie
{
  class		CountDown
  {
    using Clock = std::chrono::high_resolution_clock;
    using milliseconds = std::chrono::milliseconds;
    Clock::time_point		_t0;
    uint32_t			_rem;
    uint32_t			_init;
    mutable bool		_done;
	// t1 = Clock::now();
	// // size_t now = std::chrono::duration_cast<ms>(t1.time_since_epoch()).count();

  private:
    
  public:
    CountDown() = delete;
    CountDown(int ms);
    ~CountDown();
    CountDown(CountDown const&);
    CountDown& operator=(CountDown const&) = delete;
  public:
    void reset(int ms);
    int get() const;
    void update();
  };
}

#endif // !COUNT_DOWN_HPP
