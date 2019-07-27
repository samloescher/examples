using System;
using System.Threading.Tasks;

class Program
{
    static void Main(string[] args)
    {
        var asyncTask = DispatchAsync();
        DoSyncWork();
        asyncTask.Wait(); // Blocking call, used on the main thread
        Console.WriteLine("Async task complete? " + asyncTask.IsCompleted);
    }

    public static void DoSyncWork()
    {
        Console.WriteLine("Doing sync task before async completes");
    }
    public static async Task DispatchAsync()
    {
        await LongRunningFunction('a');
        LongRunningFunction('b'); // Forget to await! CS4014
    }

    public static async Task LongRunningFunction(char c)
    {
        Console.WriteLine("My Long Running Function Start : " + c);
        await Task.Delay(1000);
        Console.WriteLine("My Long Running Function End : " + c);
    }
}
