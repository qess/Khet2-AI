#include "Calculator.h"
#include <thread>

void Calculator::Start(const SearchParams& params, Board& board)
{
    // Start the search asynchronously.
    _thread = std::thread(&Calculator::ThreadFunc, this, params, std::ref(board));
    _thread.detach();
}

void Calculator::Stop()
{
    _search.Stop();
    if (_thread.joinable())
        _thread.join();
}

// Callback method for the thread.
void Calculator::ThreadFunc(const SearchParams& params, Board& board)
{
    _bestMove = _search.Start(params, board, _score);
}
