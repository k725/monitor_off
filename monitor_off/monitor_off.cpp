// monitor_off.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include <iostream>
#include <chrono>
#include <thread>

int main(const int argc, char** argv)
{
	static const auto SLEEP_SEC = 3;
	static const auto DESKTOP_LOCK = false;

	std::this_thread::sleep_for(std::chrono::seconds(SLEEP_SEC));

	const auto post_result = PostMessageW(HWND_BROADCAST, 0x0112, 0xF170, 2);
	if (post_result == FALSE)
	{
		std::cout << "PostMessageW Failed" << std::endl;
		return 1;
	}
	std::cout << "PostMessageW Done" << std::endl;

	if (DESKTOP_LOCK)
	{
		const auto lock_result = LockWorkStation();
		if (lock_result == FALSE)
		{
			std::cout << "LockWorkStation Failed" << std::endl;
			return 1;
		}
		std::cout << "LockWorkStation Done" << std::endl;
	}

	return 0;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
