/*
 * Basic program for Swift
 * User inputs a string
 * Program prints a random string char by 
 * Randomizes char, letter by letter, until it reaches the original string
 * I didn't have any cool ideas so I decided to just do it again but in swift,
 * language seems pretty sick so far though you can both compile and interpret
 * The way it handles types it pretty cool, it makes it very obvious when it's assuming
 * so you can really easily notice and declare explicitly instead
 */

import Foundation

// Func for generating random char, a is ascii 97, I'm gonna do the same shortcut as lastime to keep it simple
func randChar() -> Character {
    let randInd = Int.random(in: 0...25)
    return Character(UnicodeScalar(randInd + 97)!)
}

func main() {
    print("Enter a string: ", terminator: "") // the terminator tells it to use the following string "" as the terminating character instead of newline so you keep typing on the same line which looks better imo
    let s: String = readLine()!
    var cur: String = ""


    var randC: Character
    var count: Int

    for c in s {
        count = 0
        randC = randChar()
        while (randC != c) {
            count += 1
            // looks cooler if it sleeps
            Thread.sleep(forTimeInterval: 0.01)
            randC = randChar()
            // rand char can never be a space of capital letter
            // because I just want it to be cool looking
            // I decied to just set it to c if it takes more than 15 loops
            // so that way you can use any characters you want but its still
            // really simple
            if (count == 15) {
                randC = c
            }
            print(cur + String(randC))
        }
        cur += String(randC)
    }
    print(cur)
}

main()