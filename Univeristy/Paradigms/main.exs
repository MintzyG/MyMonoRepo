defmodule Meu do
  @spec run()
  def main() do
    x = IO.gets("x")
    y = IO.gets("y")
    IO.inspect(soma(x, y))
  end

  def soma(x, y) do
    x + y
  end
end
