// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "CobrowseIO",
    platforms: [
        .macOS(.v10_10), .iOS(.v9)
    ],
    products: [
        .library(name: "CobrowseIO", targets: ["CobrowseIO"])
    ],
    dependencies: [
        .package(url: "https://github.com/cobrowseio/SwiftCBOR", branch: "master"),
        .package(url: "https://github.com/daltoniam/Starscream", from: "3.0.0")
    ],
    targets: [
        .binaryTarget(name: "CobrowseIO", path: "CobrowseIO.xcframework")
    ]
)
